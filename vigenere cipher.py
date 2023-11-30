def encipher():
    input_text = input("\nEnter Plain Text: ")
    key = input("\nEnter Key Value: ")

    result_cipher_text = ""

    for i in range(len(input_text)):
        j = i % len(key)
        value = (ord(input_text[i].upper()) - ord('A') + ord(key[j].upper()) - ord('A')) % 26
        result_cipher_text += chr(ord('A') + value)

    print("\nResultant Cipher Text:", result_cipher_text)

def decipher():
    input_text = input("\nEnter Cipher Text: ")
    key = input("\nEnter Key Value: ")

    result_deciphered_text = ""

    for i in range(len(input_text)):
        j = i % len(key)
        value = (ord(input_text[i].upper()) - ord('A') - (ord(key[j].upper()) - ord('A'))) % 26
        if value < 0:
            value = value + 26

        result_deciphered_text += chr(ord('A') + value)

    print("\nResultant Deciphered Text:", result_deciphered_text)

def main():
    while True:
        print("\n1. Encrypt Text", "\t2. Decrypt Text", "\t3. Exit")
        choice = int(input("\nEnter Your Choice: "))

        if choice == 3:
            break
        elif choice == 1:
            encipher()
        elif choice == 2:
            decipher()
        else:
            print("Please Enter Valid Option.")

if __name__ == "__main__":
    main()
