#include <iostream>
#include <stack>
#include <string>

using namespace std;

class BrowserHistory {
private:
    string currpage;
    stack<string> backstack;
    stack<string> forstack;

public:
    BrowserHistory(string c) {
        currpage = c;
        cout << "Opened homepage: " << currpage << "\n";
    }

    // 1. Visit new URL: Push current page to backStack, clear forwardStack
    void visit(string n) {
        backstack.push(currpage);
        
        // Corrected: Pop elements while the stack is NOT empty
        while (!forstack.empty()) {
            forstack.pop();
        }
        
        currpage = n;
        cout << "Visiting: " << currpage << "\n";
    }

    // 2. Go Back: Move current page to forwardStack, set top of backStack as current
    void back() {
        if (backstack.empty()) {
            cout << "No back history available!\n";
            return;
        }
        forstack.push(currpage);
        currpage = backstack.top();
        backstack.pop();
        cout << "Visited previous page: " << currpage << "\n";
    }

    // 3. Go Forward: Move current page to backStack, set top of forwardStack as current
    void forward() {
        if (forstack.empty()) {
            cout << "Cannot go forward. No forward history!\n";
            return;
        }
        backstack.push(currpage);
        currpage = forstack.top();
        forstack.pop();
        cout << "Visited forward page: " << currpage << "\n";
    }

    // 4. View current page without changing stacks  
    void displayCurrent() const {
        cout << "Currently viewing: " << currpage << "\n";
    }
};

int main() {
    string homepage;
    cout << "Enter initial homepage URL: ";
    cin >> homepage;

    BrowserHistory browser(homepage);

    int choice;
    string url;

    do {
        cout << "\n==============================\n";
        cout << "    BROWSER HISTORY MENU      \n";
        cout << "==============================\n";
        cout << "1. Visit New Page\n";
        cout << "2. Go Back\n";
        cout << "3. Go Forward\n";
        cout << "4. Display Current Page\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter URL to visit: ";
                cin >> url;
                browser.visit(url);
                break;
            case 2:
                browser.back();
                break;
            case 3:
                browser.forward();
                break;
            case 4:
                browser.displayCurrent();
                break;
            case 5:
                cout << "Exiting Browser Simulator.\n";
                break;
            default:
                cout << "Invalid choice! Please enter a number from 1 to 5.\n";
        }
    } while (choice != 5);

    return 0;
}