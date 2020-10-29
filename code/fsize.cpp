/*
 * Owner: Javier Rodriguez
 * Date: 10/28/2020
 * Purpose: To return a file size.
 * Copy Right: Free Use.
*/

// Includes.
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// Functions Declaration.
void help();
int getFileSize(string fileName);

int main (int argc, char *argv[]) {
  if (argc > 2) {
    const int totalArguments = argc - 1;                       // INTEGER - Calculates total files.

    cout << "ERROR: Only one argument is expected. ";
    cout << "Arguments entered: " << totalArguments << endl;

    return 1;
  } else if (argc == 2) {
    const string fileName = argv[1];                           // STRING - File name.

    if (fileName.compare("-help") == 0) {
      help();
    } else {
      getFileSize(fileName);
    }

  } else {
    cout << "ERROR: No argument has been provided." << endl;

    return 1;
  }

  return 0;
}

/*
 * Function Name: help.
 * Function Purpose: To display program manual.
 *
 * Params:
 * Returns: Void.
 */
void help() {
  cout << "\n" << "fsize V1.0.1 manual" << "\n";
  cout << "--- " << "Instructions" << " ---" << "\n";
  cout << "fsize filename" << " - " << "returns file size in bytes.";
  cout << "\n" << endl;

  return;
}

/*
 * Function Name: getFileSize.
 * Function Purpose: To calculate a file size.
 *
 * Params:
 *       1 String - fileName
 * Returns: Void.
 */
int getFileSize (string fileName) {
  ifstream file;                                                    // IFSTREAM - File reference.

  file.open(fileName);

  if (file.is_open()) {
    streampos begin, end;                                           // STREAMPOS - Hold file size.

    begin = file.tellg();
    file.seekg(0, ios::end);
    end = file.tellg();

    cout << (end-begin) << endl;

    file.close();

    return 0;
  } else {
    cout << "ERROR: Unable to open file." << endl;
    return 1;
  }
}
