# Flight Management System

## Overview
This project is a **Flight Management System** implemented in C++ that allows users to manage flight information using **Linked Lists** and **Stacks**. Users can insert, delete, display, and edit flight data, making it a simple yet practical system for learning data structures and object-oriented programming concepts.

---

## Features

### 1. Linked List Operations
- Add a new flight.
- Delete a flight by its ID.
- Display all flights.
- Insert a flight at a specific position in the list.

### 2. Stack Operations
- Push a flight onto the stack.
- Pop the latest flight from the stack.
- Peek to see the last added flight.
- Edit flight details (ID, model, capacity, airline, destination, ticket price, departure time).
- Display all flights in the stack.

### 3. Flight Attributes
Each flight contains:
- Flight ID
- Model
- Capacity
- Airline
- Destination
- Departure Time
- Ticket Price

---

## Data Structures Used
- **Flight Class:** Represents flight information with getters and setters.
- **Linked List:** Manages flight data in a sequential list.
- **Stack:** Tracks flight data in a Last-In-First-Out (LIFO) order.
- **Node Template:** Generic node structure for both Linked List and Stack.

---

## How to Run
1. Clone or download the repository.
2. Open the project in your favorite C++ IDE (e.g., Code::Blocks, Visual Studio, or CLion) or compile using terminal:
   ```bash
   g++ -o flight_system main.cpp
   ./flight_system
