#include <iostream>
using namespace std;

//Rwan Ashraf 221001757

// Define the Flight class to represent flight information
class Flight {
private:
    int Flight_ID;
    string model;
    int capacity;
    string airline;
    string destination;
    string Departure_Time;
    double Ticket_Price ;


public:
    // default constructor
    Flight()
    {}
    // Constructor to initialize Flight attributes
    Flight(int id,string m,int c,string al,string d,string DT,double TP ){
        Flight_ID=id;
        model=m;
        capacity=c;
        airline=al;
        destination=d;
        Departure_Time=DT;
        Ticket_Price= TP;
    }
    //All Setters
    void setFlight_ID(int id)
    {
        Flight_ID=id;
    }
    void setmodel(string m)
    {
        model=m;
    }
     void setcapacity(int c )
    {
        capacity=c;
    }
     void setairline(string a)
    {
        airline=a;
    }
     void setdestnation(string d)
    {
        destination=d;
    }
     void setDeparture_Time(string dt)
    {
        Departure_Time=dt;
    }
     void setTicket_Price(double tp)
    {
        Ticket_Price=tp;
    }

    //All Getters

    int getFlight_ID()
    {
        return Flight_ID;
    }
    string getmodel()
    {
        return model;
    }
     int getcapacity()
    {
        return capacity;
    }
     string getairline()
    {
        return airline;
    }
     string getdestnation()
    {
        return destination;
    }
     string getDeparture_Time()
    {
        return Departure_Time;
    }
     double getTicket_Price()
    {
        return Ticket_Price;
    }
    //function to print flight information
    void display_Flight_info()
    {
        cout <<"your flight id is \n"<<Flight_ID;
        cout<<"\n model : \n"<<model;
        cout<<"\n capacity : \n"<<capacity;
        cout<<"\n airline : \n "<< airline;
        cout<<"\n destination : \n"<<destination;
        cout<<"\n Departure Time : \n"<<Departure_Time;
        cout<<"\n Ticket Price : \n"<<Ticket_Price;
    }
};
template <class T>

class Node{
    public:
        T data;
        Node<T>* next;

        Node(T e){
            data = e;
            next = NULL;
        }
};
template <class T>
class FlightList{
	Node<T>* head;
    public:
    	FlightList(){   //constructor
    	    head= NULL;
    	}
    	//Add new node at the end
    	void add_flight(T flight){
    		Node<T>* newNode = new Node<T>(flight);
    		Node <T>*ptr=head ;
    		if (ptr == nullptr) {
            head = newNode;
    		}
    		else{
                while(ptr->next!=nullptr)
            {
                ptr=ptr->next;
            }
            ptr->next=newNode;
    		}
    	}
    	//delete a specific flight
    	void del_flight(int flight_ID){
    	    Node <T>*ptr=head;
    	     Node <T>*ptr2=NULL;
    	     if(head==NULL){
                cout<<"List is empty \n";
                return;
    	     }

             while(ptr->data.getFlight_ID() != flight_ID)
             {
                 ptr2 = ptr;
                 ptr = ptr->next;
             }
             if (ptr == head)
            {
                head = head->next;
                delete ptr;
                return;
            }
            else{
             ptr2->next = ptr->next;
             delete ptr;
            }

    	}

    	//print all flights
      void DisplayAll()
      {
           Node <T>*ptr=head;
          if (head==NULL)
            cout<<"Linked list is empty \n ";
          else {
            while(ptr!=NULL)
          {
              ptr->data.display_Flight_info();
              ptr=ptr->next;
          }
          }
      }
      //insert a specific node at a specific position
      void Insert_new_flight(T e,int pos)
      {
          Node<T> * newNode = new Node<T>(e);
        newNode->data=e;
        if (pos==1)
        {
            newNode->next = head;
            head=newNode;
        }
        else
        {
            Node <T>*ptr=head;
        for(int i=1;i<pos-1 && ptr != NULL;i++)
        {
            ptr=ptr->next;
        }
        newNode->next=ptr->next;
        ptr->next=newNode;
        }
      }

};

//stack class
template <class T>
class Stack {
public:
   Node  <T> * top;

    Stack() {
        top = NULL;
    }
    // Function to insert an element into the stack
    void push_flight(T x) {

        Node <T>* new_node = new Node<T>(x);
        new_node->data = x;
        new_node->next = top;
        top = new_node;
        top->data.display_Flight_info();

    }


    // Function to delete an element from the stack
    void pop() {
        if (top == NULL) {
            cout << "Stack Empty" << endl;
            return ;
        }
        Node <T>* temp = top;
        top = top->next;
        delete temp;
    }



    // Function to get the top element of the stack
    T peek() {
        if (top == NULL) {
            cout << " Stack is empty" << endl;
            return T();
        }
        return top->data;
    }

    // Function to print all the elements of the stack
    void PrintStack() {
        if (top == NULL) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node <T> * temp = top;
        while (temp != NULL) {
            temp->data.display_Flight_info();
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == NULL;
    }
    // check if the flight already present or not
    bool is_duplicate( int value ){
        Node <T> *ptr=top;
        while(ptr !=nullptr)
        {
            if( ptr->data.getFlight_ID()==value )
            {
                return true; // Dublicate found
            }
            ptr=ptr->next;
        }
        return false ; //duplicate not found
    }

                Node<T> * findNode(int id)
                {
                    Node<T> * curr = top;
                    while(curr->data.getFlight_ID() != id && curr != NULL)
                    {
                        curr = curr->next;
                    }
                    return curr;
                }

                void edit_flight_id(int id,int newId)
                {
                    Node<T> * node = findNode(id);
                    if(node == NULL)
                    {
                        cout<<"id not found"<<endl;
                    }
                    else
                    {
                        node->data.setFlight_ID(newId);
                    }
                }

                void edit_flight_model(int id, string model)
                {
                    Node<T> * node = findNode(id);
                    if(node == NULL)
                    {
                        cout<<"id not found"<<endl;
                    }
                    else
                    {
                        node->data.setmodel(model);
                    }
                }

                void edit_flight_capacity(int id,int capacity)
                {
                    Node<T> * node = findNode(id);
                    if(node == NULL)
                    {
                        cout<<"id not found"<<endl;
                    }
                    else
                    {
                        node->data.setcapacity(capacity);
                    }
                }
                void edit_flight_destination(int id,string des)
                {
                    Node<T> * node = findNode(id);
                    if(node == NULL)
                    {
                        cout<<"id not found"<<endl;
                    }
                    else
                    {
                        node->data.setdestnation(des);
                    }
                }

                void edit_flight_airline(int id,string airline)
                {
                    Node<T> * node = findNode(id);
                    if(node == NULL)
                    {
                        cout<<"id not found"<<endl;
                    }
                    else
                    {
                        node->data.setairline(airline);
                    }
                }

                void edit_flight_price(int id, double price)
                {
                    Node<T> * node = findNode(id);
                    if(node == NULL)
                    {
                        cout<<"id not found"<<endl;
                    }
                    else
                    {
                        node->data.setTicket_Price(price);
                    }
                }
                void edit_flight_depature_time(int id, string dep)
                {
                    Node<T> * node = findNode(id);
                    if(node == NULL)
                    {
                        cout<<"id not found"<<endl;
                    }
                    else
                    {
                        node->data.setDeparture_Time(dep);
                    }
                }
};
int main() {
    FlightList <Flight> fl;    Stack<Flight> s;
    cout<<"Welcome to the Employee Management System"<<endl;
    cout<<"Choose of the following options to use the system features"<<endl;
    cout << "1. Linked List" << endl;
    cout << "2. Stack" << endl;
    cout << "Enter your choice: ";
    int choice;
    int e, flight_ID;
    cin >> choice;
    if (choice==1)
    {
        while (true){
        char operation ;
        cout <<"please enter I for insertion , D for delete , P to display all elements and if you want to close program enter anything else \n";
        cin>>operation;
        if (operation=='I')
        {
            int flightID,capacity;
            string model,airline,destination,Departure_Time;
            double Ticket_Price;
            cout <<"Enter Flight ID: \n" << endl;
            cin >> flight_ID;
            cout <<"Enter Model: \n" << endl;
            cin >> model;
            cout <<"Enter Capacity: \n" << endl;
            cin >>capacity;
            cout <<"Enter Airline: \n" << endl;
            cin >> airline;
            cout <<"Enter Destination: \n" << endl;
            cin >> destination;
            cout <<"Enter Departure Time: \n" << endl;
            cin >> Departure_Time;
            cout <<"Enter Ticket Price: \n" << endl;
            cin >>Ticket_Price;
            Flight newFlight(flight_ID,model,capacity,airline,destination,Departure_Time,Ticket_Price);
            fl.add_flight(newFlight);
            cout << "Congratulations flight inserted successfully!" << endl;
        }
        else if (operation=='D')
        {
             cout<<"Enter flight id : \n";
             cin>>flight_ID;
             fl.del_flight(flight_ID);
             cout<<"List after delete \n";
             fl.DisplayAll();
        }
        else if (operation=='P')
        fl.DisplayAll();
        else
            return 0;
    }
    }
    else if (choice==2)
    {
        while(true)
        {
         char op;
         cout<<"Enter 'I' to insert in stack, 'R' to remove , 'P' to know the latest added flight , 'E' for editing , 'D' to display and anything to close the program \n";
         cin>>op;
        if(op=='I')
        {
            int flightID,capacity;
            string model,airline,destination,departure_time;
            double ticket_price;
            cout <<"Enter Flight ID: \n" << endl;
            cin >> flightID;
            if (s.is_duplicate(flightID)) {
                cout << "Rejected \n" << endl;
                return 0;
            }

            cout <<"Enter Model: " << endl;
            cin >> model;

            cout <<"Enter Capacity: " << endl;
            cin >>capacity;

            cout <<"Enter Airline: " << endl;
            cin >> airline;

            cout <<"Enter Destination: " << endl;
            cin >> destination;

            cout <<"Enter Departure Time: " << endl;
            cin >> departure_time;

            cout <<"Enter Ticket Price: " << endl;
            cin >>ticket_price;

            cout << " Congrats , your Flight inserted successfully! \n " << endl;
            Flight newFlight(flightID,model,capacity,airline,destination,departure_time,ticket_price);
            fl.add_flight(newFlight);
            s.push_flight(newFlight);

        }
        else if(op=='R')
        {
            if (!s.isEmpty()) {
                    s.pop();
                    cout << "Flight successfully removed from the stack. \n " << endl;
            }
            else
            {
                cout << "Stack is empty. Cannot remove from an empty stack.\n " << endl;
            }
        }

        else if(op=='P'){
            cout <<"This is the last Flight:"<<endl;
            s.peek().display_Flight_info();
        }
        //Display all he flights
        else if(op=='D')
        {
            cout << "Printing all flights in the stack:" << endl;
            s.PrintStack();

        }
        else if(op=='E')
        {
            cout<<"please enter the flight id you want to edit"<<endl;
            int id;
            cin>>id;
            string operation;
            cout<<"What do you want to change write ID or model or capacity or airline or destination  or ticketPrice or departureTime  \n";
            cin>>operation;
            if(operation == "ID")
            {
                cout<<"enter new id"<<endl;
                int newId;
                cin>>newId;
                s.edit_flight_id(id,newId);
            }
            else if (operation=="model")
            {
                cout<<"enter new model"<<endl;
                string model;
                cin>>model;
                s.edit_flight_model(id,model);
            }
            else if (operation=="capacity")
            {
                cout<<"enter capacity"<<endl;
                int capacity;
                cin>>capacity;
                s.edit_flight_capacity(id,capacity);
            }
            else if (operation=="destination")
            {
                cout<<"enter new destination"<<endl;
                string des;
                cin>>des;
                s.edit_flight_destination(id,des);
            }
             else if (operation=="airline")
            {
                cout<<"enter new airline"<<endl;
                string airline;
                cin>>airline;
                s.edit_flight_airline(id,airline);
            }
            else if (operation=="ticketPrice")
            {
                double price;
                cin>>price;
                s.edit_flight_price(id,price);
            }
            else if (operation=="departureTime")
            {
                cout<<"enter new depature time"<<endl;
                string dep;
                cin>>dep;
                s.edit_flight_depature_time(id,dep);
            }
            else
                cout<<"your choice is invalid \n ";
             cout<<"Stack after editing : \n";
             s.PrintStack();
        }
        else
            return 0;
    }
    }
    else
        cout<<"Please choose only between 1 and 2 .";

    return 0;
}
