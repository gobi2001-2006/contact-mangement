#include <iostream>
#include <string>

using namespace std;

// Node structure for BST
struct Contact {
    string name, phone;
    Contact* left;
    Contact* right;

    Contact(string n, string p) : name(n), phone(p), left(nullptr), right(nullptr) {}
};

// BST Class
class ContactBST {
private:
    Contact* root;

    Contact* insert(Contact* node, string name, string phone) {
        if (!node) return new Contact(name, phone);
        if (name < node->name) node->left = insert(node->left, name, phone);
        else if (name > node->name) node->right = insert(node->right, name, phone);
        return node;
    }

    Contact* search(Contact* node, string name) {
        if (!node || node->name == name) return node;
        return (name < node->name) ? search(node->left, name) : search(node->right, name);
    }

    void inorder(Contact* node) {
        if (!node) return;
        inorder(node->left);
        cout << "📞 " << node->name << " - " << node->phone << endl;
        inorder(node->right);
    }

public:
    ContactBST() : root(nullptr) {}

    void add(string name, string phone) {
        root = insert(root, name, phone);
        cout << "✅ Contact Added: " << name << endl;
    }

    void search(string name) {
        Contact* found = search(root, name);
        cout << (found ? "🔍 Found: " + found->name + " - " + found->phone : "❌ Not Found!") << endl;
    }

    void display() {
        cout << "📋 Contact List:\n";
        inorder(root);
        if (!root) cout << "📂 No contacts available!\n";
    }
};

// Main Function
int main() {
    ContactBST contacts;
    int choice;
    string name, phone;

    while (true) {
        cout << "\n📞 Contact Manager\n";
        cout << "1️⃣ Add Contact\n2️⃣ Search Contact\n3️⃣ Display Contacts\n4️⃣ Exit\n👉 Choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            cout << "👤 Name: "; getline(cin, name);
            cout << "📞 Phone: "; getline(cin, phone);
            contacts.add(name, phone);
        } 
        else if (choice == 2) {
            cout << "🔍 Search Name: "; getline(cin, name);
            contacts.search(name);
        } 
        else if (choice == 3) contacts.display();
        else if (choice == 4) {
            cout << "👋 Exiting... Thank you!\n";
            break;
        } 
        else cout << "❌ Invalid Choice! Try again.\n";
    }
    return 0;
}
