#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void displayMenu() {
    cout << "\nBasic Text Editor\n";
    cout << "Commands:\n";
    cout << "1. Open a file\n";
    cout << "2. Save the file\n";
    cout << "3. Edit the file\n";
    cout << "4. Display the file content\n";
    cout << "5. Exit\n";
}

void openFile(const string& filename, vector<string>& lines) {
    ifstream file(filename);
    if (!file) {
        cout << "Error opening file: " << filename << endl;
        return;
    }
    lines.clear();
    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }
    file.close();
    cout << "File opened successfully: " << filename << endl;
}

void saveFile(const string& filename, const vector<string>& lines) {
    ofstream file(filename);
    if (!file) {
        cout << "Error saving file: " << filename << endl;
        return;
    }
    for (const auto& line : lines) {
        file << line << endl;
    }
    file.close();
    cout << "File saved successfully: " << filename << endl;
}

void editFile(vector<string>& lines) {
    cout << "Enter the line number to edit (1 to " << lines.size() << "): ";
    int lineNumber;
    cin >> lineNumber;
    cin.ignore(); // Ignore the newline character left in the input buffer

    if (lineNumber < 1 || lineNumber > lines.size()) {
        cout << "Invalid line number." << endl;
        return;
    }

    cout << "Current line: " << lines[lineNumber - 1] << endl;
    cout << "Enter new text: ";
    string newText;
    getline(cin, newText);
    lines[lineNumber - 1] = newText;
    cout << "Line updated." << endl;
}

void displayFileContent(const vector<string>& lines) {
    cout << "File Content:\n";
    for (size_t i = 0; i < lines.size(); ++i) {
        cout << (i + 1) << ": " << lines[i] << endl;
    }
}

int main() {
    vector<string> lines;
    string filename;
    int choice;

    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter filename to open: ";
                cin >> filename;
                openFile(filename, lines);
                break;
            case 2:
                cout << "Enter filename to save: ";
                cin >> filename;
                saveFile(filename, lines);
                break;
            case 3:
                editFile(lines);
                break;
            case 4:
                displayFileContent(lines);
                break;
            case 5:
                cout << "Exiting the editor." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}