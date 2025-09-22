# 💳 Payment Processing System: Managing Transactions with Stacks and Queues

This project simulates a **payment processing system** using **C++ data structures**.  
It leverages **queues** for managing pending payments (FIFO) and **stacks** for storing processed payments (LIFO).  
This dual-structure ensures efficient handling of upcoming payments while maintaining a history of completed transactions.  

---

## 🚀 Features
- Add payments (Electricity, Grocery, etc.)
- Process payments (FIFO order using Queue)
- Store completed transactions in a Stack (LIFO order)
- View **pending** and **paid** payments separately
- Delete recent payment history (Stack `pop`)
- Check **total pending funds** and **total paid funds**
- Two implementations:
  - **Array-based**
  - **Linked list-based**

---

## 🛠️ Data Structures Used
- **Stack (LIFO):** For storing processed (paid) transactions  
- **Circular Queue (FIFO):** For managing pending transactions  
- **Linked List:** Alternative implementation for dynamic memory management  

---

## 📂 Project Structure
- `array_implementation.cpp` → Payment system using **Stack + Circular Queue (Array)**  
- `linkedlist_implementation.cpp` → Payment system using **Stack + Queue (Linked List)**  

---

## ⚙️ How It Works
1. **Add Payment:** Insert into the **queue** (pending list).  
2. **Process Payment:** Dequeue payment → Push to **stack** (paid history).  
3. **View Pending Payments:** Traverse the queue.  
4. **View Paid Payments:** Traverse the stack.  
5. **Delete Recent History:** Pop the top payment from the stack.  
6. **Check Funds:** Display total pending and paid amounts.  

---

## 📸 Sample Menu
