// Using Array
#include <iostream>
#include <string>
#define MAX 100
using namespace std;

class Stack
{
public:
    int top;
    string description_stack[MAX];
    double amount_stack[MAX];

    Stack()
    {
        top = -1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == MAX - 1;
    }

    void push(string Str, double lng)
    {
        if (isFull())
        {
            cout << "The stack is full! Unable to add any more paid payments history at this time.\n";
        }
        else
        {
            top++;
            description_stack[top] = Str;
            amount_stack[top] = lng;
        }
    }

    void pop_payment()
    {
        if (isEmpty())
        {
            cout << "You don't have any recent payment history at the moment." << endl;
            return;
        }
        cout << "Your recent payment history has been deleted." << endl;
        cout << "Type of Transaction: " << description_stack[top] << endl;
        cout << "Amount: Rs. " << amount_stack[top] << endl;
        top--;
        return;
    }

    void paid_payment()
    {
        cout << "--------------------------------------------------------------------" << endl;
        cout << "               *****    Payment Stack Status    *****               " << endl;
        cout << "--------------------------------------------------------------------" << endl;

        if (isEmpty())
        {
            cout << "                      || No paid payments ||                     " << endl;
            cout << "--------------------------------------------------------------------" << endl;
        }
        else
        {
            for (int i = top; i >= 0; i--)
            {
                cout << "Type of Transaction: " << description_stack[i] << endl;
                cout << "Amount: Rs. " << amount_stack[i] << endl;
            }
            cout << "\n--------------------------------------------------------------------\n";
        }
    }

    void paid_funds()
    {
        if (isEmpty())
        {
            cout << "You haven't made any payments yet." << endl;
            return;
        }
        double amountpaid = 0;
        for (int i = 0; i <= top; i++)
        {
            amountpaid += amount_stack[i];
        }
        cout << "You have paid ₹" << amountpaid << " till now." << endl;
    }
};

class CircularQueue : public Stack
{
    int front, rear;
    string description_queue[MAX];
    double amount_queue[MAX];

public:
    CircularQueue() { front = rear = -1; }

    bool isfull()
    {
        return (rear + 1) % MAX == front;
    }

    bool isempty()
    {
        return front == -1;
    }

    void Addpayment_Queue(string desc, double amt)
    {
        if (isfull())
        {
            cout << "The queue is full! Unable to add any more payments at this time.\n";
            return;
        }
        else if (isempty())
        {
            front = rear = 0;
            description_queue[rear] = desc;
            amount_queue[rear] = amt;
        }
        else
        {
            rear = (rear + 1) % MAX;
            description_queue[rear] = desc;
            amount_queue[rear] = amt;
        }
    }

    void process_payment()
    {
        if (front == -1)
        {
            cout << "Currently, there are no pending payments!\n";
            return;
        }
        string desc = description_queue[front];
        double amt = amount_queue[front];

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
        cout << "Payment of Rs. " << amt << " for " << desc << " has been successfully processed!\n";
        push(desc, amt);
    }

    void pending_payment()
    {
        cout << "--------------------------------------------------------------------" << endl;
        cout << "               *****    Payment Queue Status    *****               " << endl;
        cout << "--------------------------------------------------------------------" << endl;

        if (isempty())
        {
            cout << "                   || No pending payments ||                      " << endl;
            cout << "--------------------------------------------------------------------" << endl;
            return;
        }
        int i = front;
        while (i != rear)
        {
            cout << "Type of Transaction: " << description_queue[i] << endl;
            cout << "Amount: Rs. " << amount_queue[i] << endl;
            i = (i + 1) % MAX;
        }
        cout << "Type of Transaction: " << description_queue[rear] << endl;
        cout << "Amount: Rs. " << amount_queue[rear] << endl;
        cout << "\n--------------------------------------------------------------------\n";
    }

    void pending_funds()
    {
        if (isempty())
        {
            cout << "You don't have any pending payments at the moment.\n";
            return;
        }
        double amountToPay = 0;
        int i = front;
        while (i != rear)
        {
            amountToPay += amount_queue[i];
            i = (i + 1) % MAX;
        }
        amountToPay += amount_queue[rear];
        cout << "You have ₹" << amountToPay << " in pending payments. Please complete your payments to avoid delays." << endl;
    }
};

int main()
{
    CircularQueue paymentSystem;

    int ch;
    string description;
    double amount;

    cout << "The Options are : " << endl;
    cout << "1: Add Payment." << endl
         << "2: Process Payment." << endl
         << "3: View Pending Payments." << endl
         << "4: View Paid Payments." << endl
         << "5: Delete recent history." << endl
         << "6: Check your total pending payments amount." << endl
         << "7: Check your total paid payments amount." << endl
         << "8: Exit." << endl;
    do
    {
        cout << "\nEnter your choice: ";
        cin >> ch;
        cin.ignore(); // To ignore newline after integer input
        switch (ch)
        {
        case 1:
            cout << "Enter the type of transaction (e.g. Electricity, Grocery) : ";
            getline(cin, description);
            cout << "Enter the amount (Rs.) : ";
            cin >> amount;
            paymentSystem.Addpayment_Queue(description, amount);
            break;
        case 2:
            paymentSystem.process_payment();
            break;
        case 3:
            paymentSystem.pending_payment();
            break;
        case 4:
            paymentSystem.paid_payment();
            break;

        case 5:
            paymentSystem.pop_payment();
            break;

        case 6:
            paymentSystem.pending_funds();
            break;

        case 7:
            paymentSystem.paid_funds();
            break;

        case 8:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid option, please try again.\n";
        }
    } while (ch != 8);

    return 0;
}
