#For Q1

# Data Structures Used:
Hash map for O(1) key lookups
Doubly linked list to maintain access order

# Operations Used:
`get(key)`: Returns value if exists, -1 otherwise
`put(key, value)`: Inserts/updates value, evicting LRU item if full



# Q2 


##  Data Structures Used

| Data Structure                    | Purpose                                        |
|----------------------------------|------------------------------------------------|
| `vector<list<pair<int, int>>>`   | The main hash table (buckets for each hash)   |
| `list<pair<int, int>>`           | Used for chaining key-value pairs in a bucket |
| `pair<int, int>`                 | Stores each key-value mapping                 |


# Q3

#  Book Review App

An Android application that allows users to browse, rate, and review books. This app provides a clean and intuitive interface for users to explore books and share their opinions.

##  Features

-  View a list of books with details like title, author, and cover
-  Rate and review books
-  Search functionality for finding books quickly
-  Add new books to the collection
-  View other users' reviews
-  Clean and user-friendly UI

## 🛠 Tech Stack

- **Java / Kotlin** (depending on your implementation)
- **Firebase** – for authentication and real-time database
- **XML** – for UI layout
- **Android Studio** – IDE used for development

##  Setup Instructions

1. Clone the repository:
