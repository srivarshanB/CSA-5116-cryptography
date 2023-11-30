def encrypt(plaintext, key):
    len_plain = len(plaintext)
    key_len = len(key)

    # Create an array to store the column indices based on the key
    key_order = [i for i in range(key_len)]

    # Sort the key_order array based on the letters of the key
    for i in range(key_len - 1):
        for j in range(key_len - i - 1):
            if key[j] > key[j + 1]:
                # Swap key_order elements if the corresponding key letters are out of order
                key_order[j], key_order[j + 1] = key_order[j + 1], key_order[j]

    # Calculate the number of rows required
    rows = len_plain // key_len
    if len_plain % key_len != 0:
        rows += 1

    # Create a 2D array to hold the characters in the table
    table = [[' ' for _ in range(key_len)] for _ in range(rows)]

    # Fill in the table with the plaintext
    index = 0
    for i in range(rows):
        for j in range(key_len):
            if index < len_plain:
                table[i][key_order[j]] = plaintext[index]
                index += 1

    # Print the encrypted message column by column
    encrypted_message = ""
    for j in range(key_len):
        for i in range(rows):
            if table[i][j] != ' ':
                encrypted_message += table[i][j]

    print("Encrypted Message:", encrypted_message)

def main():
    plaintext = input("Enter the plaintext: ")
    key = input("Enter the key: ")

    # Encrypt the message
    encrypt(plaintext, key)

if __name__ == "__main__":
    main()
