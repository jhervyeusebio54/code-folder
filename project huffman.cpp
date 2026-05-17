#include <iostream>      // Includes input/output stream library for console I/O
#include <fstream>       // Includes file stream library for file reading/writing
#include <sstream>       // Includes string stream library for parsing text
#include <string>        // Includes string class definitions
using namespace std;     // Allows usage of standard library names without std::

struct HuffNode {
    int value;           // Stores frequency of a character
    char ch;             // Stores the character itself (for leaf nodes)
    HuffNode* next;      // Pointer for maintaining sorted linked list
    HuffNode* left;      // Left child in the Huffman tree
    HuffNode* right;     // Right child in the Huffman tree

    // Constructor initializes node with given frequency and character
    HuffNode(int x, char c) : value(x), ch(c), next(nullptr), left(nullptr), right(nullptr) {}
};

int arrayChar[256];      // Global array to count frequency of each ASCII character

class Huffman {
public:
    HuffNode* head;                  // Pointer to head of priority queue (sorted linked list)
    HuffNode* huff;                  // Root of the final Huffman tree
    string huffmancode[256];         // Array storing Huffman code for each ASCII character
    int originalSize;                // Stores original file size for compression metrics

    // Constructor initializes defaults
    Huffman() : head(nullptr), huff(nullptr), originalSize(0) {}

    void huffmanCode(HuffNode* r, string codePerChar);            // Recursively generates Huffman codes
    HuffNode* generateHuffman();                                 // Builds full Huffman tree
    void add_queue();                                            // Converts character frequencies into initial nodes
    void enqueue(HuffNode* newNode);                             // Inserts node into sorted queue
    void save_huffmancodes(HuffNode* r, ofstream& fpc);          // Saves Huffman codes to file
    string code(char& c);                                        // Retrieves Huffman code for a character
    void save_file(string bin);                                  // Saves compressed binary output to file
    long file_size(const string& filename);                      // Reads file size in bytes
    void compress(string filename);                              // Compresses file
    void decode(string& binary, HuffNode* root, ofstream& fout); // Decodes binary string during decompression
    void decompress(string filename);                            // Decompresses Huffman-encoded file
};

void Huffman::huffmanCode(HuffNode* r, string codePerChar) {
    if (!r) return;                               // Base case: null node, stop recursion

    huffmanCode(r->left, codePerChar + "0");      // Traverse left: append '0' to code
    huffmanCode(r->right, codePerChar + "1");     // Traverse right: append '1' to code

    if (!r->left && !r->right) {                  // Leaf node: actual character
        cout << r->ch << "\t" << r->value << "\t" << codePerChar << endl; // Print char, frequency, code
        huffmancode[(int)r->ch] = codePerChar;    // Store Huffman code in lookup table
    }
}

HuffNode* Huffman::generateHuffman() {
    while (head && head->next) {                  // Continue until only one node remains
        HuffNode* first = head;                   // Extract lowest-frequency node
        HuffNode* second = head->next;            // Extract second-lowest-frequency node

        HuffNode* merged =
            new HuffNode(first->value + second->value, '\0'); // Create merged node

        merged->left = first;                     // Assign children
        merged->right = second;

        head = second->next;                      // Move head forward
        enqueue(merged);                          // Insert merged node back into queue
    }

    huff = head;                                  // Remaining node is the root
    head = nullptr;                               // Clear queue
    return huff;                                  // Return Huffman tree root
}

void Huffman::add_queue() {
    for (int i = 0; i < 256; i++) {               // Iterate through all ASCII characters
        if (arrayChar[i] > 0) {                   // If character has non-zero frequency
            HuffNode* temp =
                new HuffNode(arrayChar[i], (char)i); // Create new leaf node
            enqueue(temp);                         // Insert into priority queue
        }
    }

    cout << "\nHUFFMAN TABLE:\n";                 // Print table header
    cout << "CHAR\tFREQ\tHUFFMAN CODE\n";

    HuffNode* root = generateHuffman();           // Build Huffman tree
    huffmanCode(root, "");                        // Generate Huffman codes starting from root
}

void Huffman::enqueue(HuffNode* newNode) {
    if (!head || newNode->value < head->value) {  // Insert at head if queue is empty or new node smaller
        newNode->next = head;
        head = newNode;
    } else {
        HuffNode* current = head;                 // Traverse queue
        while (current->next &&
               newNode->value >= current->next->value)
            current = current->next;              // Move until correct insertion point found

        newNode->next = current->next;            // Insert into list
        current->next = newNode;
    }
}

void Huffman::save_huffmancodes(HuffNode* r, ofstream& fpc) {
    if (!r) return;                               // Null node, stop recursion

    save_huffmancodes(r->left, fpc);              // Visit left subtree
    save_huffmancodes(r->right, fpc);             // Visit right subtree

    if (!r->left && !r->right) {                  // Leaf node: write code entry
        int freq = r->value;                      // Character frequency
        string code = huffmancode[(int)r->ch];    // Retrieve Huffman code

        // Write special tokens for whitespace characters
        if (r->ch == ' ')
            fpc << "sp " << freq << " " << code << "\n";
        else if (r->ch == '\n')
            fpc << "newline " << freq << " " << code << "\n";
        else if (r->ch == '\t')
            fpc << "tab " << freq << " " << code << "\n";
        else
            fpc << r->ch << " " << freq << " " << code << "\n"; // Write normal entry
    }
}


string Huffman::code(char& c) { return huffmancode[(int)c]; }

void Huffman::save_file(string bin) {
    ofstream fcompressed("Compressed.txt", ios::binary);
    if (!fcompressed.is_open()) {
        cout << "Error writing Compressed.txt\n";
        return;
    }
    char count = 0;
    for (int i = 0; i < 256; i++)
        if (arrayChar[i] > 0)
            count++;
    fcompressed.write(&count, 1);
    for (int i = 0; i < 256; i++) {
        if (arrayChar[i] == 0) continue;
        char ch = (char)i;
        int freq = arrayChar[i];
        string code = huffmancode[i];
        char L = (char)code.size();
        int numBytes = (code.size() + 7) / 8;
        fcompressed.write(&ch, 1);
        fcompressed.write((char*)&freq, 4);
        fcompressed.write(&L, 1);
        char byte = 0;
        int bitCount = 0;
        for (char b : code) {
            byte <<= 1;
            if (b == '1') byte |= 1;
            bitCount++;

            if (bitCount == 8) {
                fcompressed.write(&byte, 1);
                bitCount = 0;
                byte = 0;
            }
        }
        if (bitCount > 0) {
            byte <<= (8 - bitCount);
            fcompressed.write(&byte, 1);
        }
    }
    fcompressed.write((char*)&originalSize, 4);
    char byte = 0;
    int bitCount = 0;
    for (char b : bin) {
        byte <<= 1;
        if (b == '1') byte |= 1;
        bitCount++;
        if (bitCount == 8) {
            fcompressed.write(&byte, 1);
            bitCount = 0;
            byte = 0;
        }
    }
    if (bitCount > 0) {
        byte <<= (8 - bitCount);
        fcompressed.write(&byte, 1);
    }
    fcompressed.close();
}

long Huffman::file_size(const string& filename) {
    ifstream file(filename, ios::binary | ios::ate);
    if (!file.is_open()) return -1;
    long size = file.tellg();
    file.close();
    return size;
}

void Huffman::compress(string filename) {
    ifstream fp(filename, ios::binary);
    if (!fp.is_open()) {
        cout << "Error: File does not exist.\n";
        return;
    }
    fill(begin(arrayChar), end(arrayChar), 0);
    char c;
    string content, bin;
    while (fp.get(c)) {
        content += c;
        arrayChar[(int)(unsigned char)c]++;
    }
    fp.close();
    cout << "Original file size: " << file_size (filename) << " bytes\n";
    add_queue();
    for (char ch : content) bin += code(ch);
    originalSize = static_cast<int>(bin.size());
    save_file(bin);
    cout << "\nCompression is completed successfully!";
    cout << "\n\nCompressed file size: " << file_size ("Compressed.txt") << " bytes";
    cout << "\nCompressed file is saved to Compressed.txt\n";
}

void Huffman::decode(string& binary, HuffNode* root, ofstream& fout) {
    HuffNode* temp = root;
    for (char b : binary) {
        temp = (b == '1') ? temp->right : temp->left;
        if (!temp->left && !temp->right) {
            fout.put(temp->ch);
            cout << temp->ch;
            temp = root;
        }
    }
}

void Huffman::decompress(string filename) {
    ifstream fp(filename, ios::binary);
    if (!fp.is_open()) {
        cout << "Error: Compressed file not found.\n";
        return;
    }
    huff = new HuffNode(0, '\0');
    char count;
    fp.read(&count, 1);
    for (int i = 0; i < (unsigned char)count; i++) {
        char ch;
        int freq;
        char L;
        fp.read(&ch, 1);
        fp.read((char*)&freq, 4);
        fp.read(&L, 1);
        int bytesNeeded = ((int)L + 7) / 8;
        char* codeBytes = new char[bytesNeeded];
        fp.read(codeBytes, bytesNeeded);
        string codeStr;
        codeStr.reserve(L);
        int bitsDecoded = 0;
        for (int b = 0; b < bytesNeeded; b++) {
            unsigned char byte = (unsigned char)codeBytes[b];
            for (int bit = 7; bit >= 0; bit--) {
                char bitVal = ((byte >> bit) & 1) ? '1' : '0';
                codeStr += bitVal;
                bitsDecoded++;
                if (bitsDecoded == L) break;
            }
            if (bitsDecoded == L) break;
        }
        delete[] codeBytes;
        HuffNode* temp = huff;
        for (char bit : codeStr) {
            if (bit == '0') {
                if (!temp->left) temp->left = new HuffNode(0, '\0');
                temp = temp->left;
            } else {
                if (!temp->right) temp->right = new HuffNode(0, '\0');
                temp = temp->right;
            }
        }
        temp->ch = ch;
    }
    fp.read((char*)&originalSize, 4);
    string binary;
    binary.reserve(originalSize);
    char byteRead;
    while (fp.read(&byteRead, 1)) {
        unsigned char b = (unsigned char)byteRead;
        for (int i = 7; i >= 0; i--)
            binary += ((b >> i) & 1) ? '1' : '0';
    }
    fp.close();
    string actualBinary = binary.substr(0, originalSize);
    cout << "\nDECODED FILE CONTENT:\n";
    ofstream fout("Decompressed.txt", ios::binary);
    decode(actualBinary, huff, fout);
    fout.close();
    cout << "\n\nDecompression is completed successfully!";
    cout << "\n\nDecompressed file size: "<< file_size("Decompressed.txt") << " bytes";
    cout << "\nDecompressed file is saved to Decompressed.txt\n";
}

int menu() {
    int choice;
    system("cls");
    cout << "\nC++ FILE COMPRESSION/DECOMPRESSION USING HUFFMAN ALGORITHM\n";
    cout << "1. Compress File\n";
    cout << "2. Decompress File\n";
    cout << "3. Exit\n";
    cout << "Enter your choice (Select 1-3 Only): ";
    cin >> choice;
    return choice;
}

int main() {
    Huffman hm;
    while (true) {
        switch (menu()) {
            case 1: {
                system("cls");
                string filename;
                cout << "Input a file to compress: ";
                cin >> filename;
                hm.compress(filename);
                system("pause");
                break;
            }
            case 2: {
                system("cls");
                string filename;
                cout << "Input a file to decompress: ";
                cin >> filename;
                hm.decompress(filename);
                system("pause");
                break;
            }
            case 3:
                cout << "Exiting program...\n";
                exit(0);
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
