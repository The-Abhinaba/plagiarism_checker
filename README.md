# Plagiarism Checker in C  

## Overview  
The Plagiarism Checker is a lightweight and efficient tool written in C that compares multiple text files, including TXT and PDF, to detect similarity using the Jaccard Similarity algorithm. This project is designed to help users identify potential plagiarism in documents.  

---

## Project Structure  

```
plagiarism_checker  
 ├── main.c               # Main execution file  
 ├── file_handler.c       # Handles file reading (TXT & PDF)  
 ├── file_handler.h       # Header for file handling functions  
 ├── string_matching.c    # Implements Jaccard similarity  
 ├── string_matching.h    # Header for plagiarism detection  
 ├── utils.c              # Helper functions (text processing)  
 ├── utils.h              # Header for utility functions  
 ├── Makefile             # Compilation automation  
 ├── README.md            # Documentation  
 ├── .gitignore           # Ignore compiled files  
 ├── test_files/          # Sample test documents  
```

---

## Installation and Setup  

### Step 1: Clone the Repository  

```sh
git clone https://github.com/YOUR_GITHUB_USERNAME/plagiarism_checker.git  
cd plagiarism_checker  
```

### Step 2: Build the Project  

#### Using Makefile (Recommended)  

```sh
make  
```

#### Manually Using GCC  

```sh
gcc main.c file_handler.c string_matching.c utils.c -o plagiarism_checker  
```

---

## Usage  

### Compare Two Files  

```sh
./plagiarism_checker file1.txt file2.txt  
```

### Compare Multiple Files  

```sh
./plagiarism_checker file1.txt file2.txt file3.txt  
```

The program will output a similarity percentage, indicating how much text is common between the files.  

---

## How It Works  

1. Reads input files (TXT and PDF)  
2. Tokenizes and cleans text (removes punctuation, converts to lowercase)  
3. Compares files using Jaccard Similarity  
4. Displays plagiarism percentage  

---

## Dependencies  

- GCC Compiler (Install with `sudo apt install gcc` on Ubuntu)  
- pdftotext (Install with `sudo apt install poppler-utils` for PDF support)  

---

## Example Output  

```sh
$ ./plagiarism_checker file1.txt file2.txt  
Plagiarism Similarity: 52.45%  
```

---

## Contributing  

Contributions are welcome! To contribute:  

1. Fork the repository  
2. Create a new branch (`git checkout -b feature-branch`)  
3. Commit your changes (`git commit -m "Add new feature"`)  
4. Push the changes (`git push origin feature-branch`)  
5. Open a Pull Request  

---

## License  

This project is open-source and available under the MIT License.  

---

## Author  

Abhinaba Ghosh  
GitHub: https://github.com/The-Abhinaba  

---

### Follow for More Projects  

Star this repository if you find it useful!  

---
