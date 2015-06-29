#include "Headers.h"

const int n = 4;

void func(shared_ptr<Dictionary> dictionary, char matrix[n][n], int currentRow, int currentCol, set<pair<int, int>>& pathIndices, string& word)
{
    if (currentRow < 0 || currentRow >= n)
        return;

    if (currentCol < 0 || currentCol >= n)
        return;

    auto index = make_pair(currentRow, currentCol);
    bool exists = pathIndices.find(index) != pathIndices.end();
    if (exists)
        return;

    if (!word.empty() && !dictionary->IsPrefixPresent(word))
        return;

    pathIndices.insert(index);
    word.push_back(matrix[currentRow][currentCol]);

    if (dictionary->IsWordPresent(word))
        cout << word.c_str() << endl;

    func(dictionary, matrix, currentRow - 1, currentCol - 1, pathIndices, word);
    func(dictionary, matrix, currentRow - 1, currentCol + 1, pathIndices, word);

    func(dictionary, matrix, currentRow - 1, currentCol, pathIndices, word);
    func(dictionary, matrix, currentRow, currentCol + 1, pathIndices, word);
    func(dictionary, matrix, currentRow + 1, currentCol, pathIndices, word);
    func(dictionary, matrix, currentRow, currentCol - 1, pathIndices, word);

    func(dictionary, matrix, currentRow + 1, currentCol - 1, pathIndices, word);
    func(dictionary, matrix, currentRow + 1, currentCol + 1, pathIndices, word);

    word.pop_back();
    pathIndices.erase(index);
}

int main()
{
    char wordMatrix[n][n] = {
        { 'd', 'g', 'h', 'i' },
        { 'k', 'l', 'p', 's' },
        { 'y', 'e', 'u', 't' },
        { 'E', 'o', 'r', 'n' }
    };

    shared_ptr<Dictionary> dictionary = make_shared<Dictionary>();

    string words[] = { "puts", "put", "sure", "spurt", "super" };
    for (auto word : words)
        dictionary->insert(word);

    /*for (auto word : words)
        cout << (true == dictionary->IsWordPresent(word) ? word + " " + "true" : word + " " + "false").c_str() << endl;*/

    /*string temp = "supr";
    cout << (true == dictionary->IsPrefixPresent(temp) ? temp + " " + "true" : temp + " " + "false").c_str() << endl;
    temp = "sup";
    cout << (true == dictionary->IsPrefixPresent(temp) ? temp + " " + "true" : temp + " " + "false").c_str() << endl;*/

    string word;
    set<pair<int, int>> pathIndices;

    //for (int i = 0; i < n; i++)
    //for (int j = 0; j < n; j++)
        func(dictionary, wordMatrix, 1, 3, pathIndices, word);

    cout << endl << "Press any key to continue..." << endl;
    cin.get();

    return 0;
}
