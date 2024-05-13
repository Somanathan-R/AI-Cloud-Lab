#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
struct Person {
    string name;

    Person(string n) : name(n) {}
};


struct Predicate {
    string name;
    vector<Person*> args;

    Predicate(string n, vector<Person*> a) : name(n), args(a) {}

    bool operator<(const Predicate& other) const {
        if (name != other.name)
            return name < other.name;
        return args < other.args; 
    }
};

class KnowledgeBase {
private:
    set<Predicate> facts;

public:
    void addFact(const Predicate& fact) {
        facts.insert(fact);
    }

    bool hasFact(const Predicate& query) const {
        return facts.find(query) != facts.end();
    }
};

// Function to print the result of a query
void printResult(const Predicate& query, bool result) {
    if (result) {
        cout << "The relationship '" << query.name << "'";
        for (size_t i = 0; i < query.args.size(); ++i) {
            cout << " " << query.args[i]->name;
            if (i < query.args.size() - 1) {
                cout << " and";
            }
        }
        cout << " holds." << endl;
    } else {
        cout << "The relationship '" << query.name << "'";
        for (size_t i = 0; i < query.args.size(); ++i) {
            cout << " " << query.args[i]->name;
            if (i < query.args.size() - 1) {
                cout << " and";
            }
        }
        cout << " does not hold." << endl;
    }
}

int main() {
    // Construct a knowledge base with facts about family relationships
    KnowledgeBase kb;

    // Add facts to the knowledge base
    kb.addFact(Predicate("parent", {new Person("Alice"), new Person("Bob")}));
    kb.addFact(Predicate("parent", {new Person("Alice"), new Person("Charlie")}));
    kb.addFact(Predicate("parent", {new Person("Bob"), new Person("David")}));
    kb.addFact(Predicate("parent", {new Person("Bob"), new Person("Emily")}));
    kb.addFact(Predicate("parent", {new Person("Charlie"), new Person("Frank")}));
    kb.addFact(Predicate("parent", {new Person("Emily"), new Person("Grace")}));

    // Generate a query
    Predicate query("sibling", {new Person("Alice"), new Person("Bob")});

    // Check if the query is true based on the knowledge base
    bool result = kb.hasFact(query);

    // Print the result of the query
    printResult(query, result);

    return 0;
}
