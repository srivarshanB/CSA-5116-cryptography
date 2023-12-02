def generate_playfair_key(key):
    # Function to generate the Playfair cipher key matrix
    key_matrix = [['' for _ in range(5)] for _ in range(5)]
    key = key.replace('J', 'I')  # Replace J with I
    key_set = set(key)

    # Fill in the key matrix with unique characters from the key
    row, col = 0, 0
    for char in key_set.union('ABCDEFGHIKLMNOPQRSTUVWXYZ'):
        key_matrix[row][col] = char
        col += 1
        if col == 5:
            col = 0
            row += 1

    return key_matrix

def find_position(matrix, char):
    # Function to find the position of a character in the Playfair key matrix
    for i in range(5):
        for j in range(5):
            if matrix[i][j] == char:
                return i, j

def encrypt_playfair(plaintext, key):
    # Function to encrypt a plaintext using the Playfair cipher
    key_matrix = generate_playfair_key(key)
    ciphertext = ''
    plaintext = plaintext.replace('J', 'I')  # Replace J with I in the plaintext

    # Generate pairs of characters (digraphs) from the plaintext
    pairs = [plaintext[i:i+2] for i in range(0, len(plaintext), 2)]
    if len(pairs[-1]) == 1:
        pairs[-1] += 'X'  # Add an 'X' to the last pair if it contains a single character

    for pair in pairs:
        # Find the positions of the two characters in the key matrix
        row1, col1 = find_position(key_matrix, pair[0])
        row2, col2 = find_position(key_matrix, pair[1])

        # If the characters are in the same row, replace them with the characters to their right (circularly)
        if row1 == row2:
            ciphertext += key_matrix[row1][(col1 + 1) % 5] + key_matrix[row2][(col2 + 1) % 5]
        # If the characters are in the same column, replace them with the characters below (circularly)
        elif col1 == col2:
            ciphertext += key_matrix[(row1 + 1) % 5][col1] + key_matrix[(row2 + 1) % 5][col2]
        # If the characters form a rectangle, replace them with the characters in the same row but opposite column
        else:
            ciphertext += key_matrix[row1][col2] + key_matrix[row2][col1]

    return ciphertext

def main():
    # Example usage
    key = "KEYWORD"
    plaintext = "HELLO"
    encrypted_text = encrypt_playfair(plaintext, key)

    print("Plaintext:", plaintext)
    print("Key:", key)
    print("Encrypted text:", encrypted_text)

if __name__ == "__main__":
    main()
