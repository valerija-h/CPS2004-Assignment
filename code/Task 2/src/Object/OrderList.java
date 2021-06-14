package Object;

import Observer.Observer;

import java.util.ArrayList;

public class OrderList {
    private Order head;
    private Order end;
    private Observer observer;

    public OrderList(){
        head = new Order(null, null, null,0f , null);
    }

    //Adds a new Order/Node to the current Order List/Linked List and updates the observer.
    public void addOrder(String restaurantName, String deliveryType, ArrayList<String> items, float total, Restaurant restaurant){
        Order newOrder = new Order(restaurantName,deliveryType,items,total,restaurant);
        //If the head is null, add the order to the start of the order list.
        if(head.getRestaurantName() == null && head.getDeliveryType() == null && head.getItems() == null){
            head = newOrder;
            end = newOrder;
            observer.update();
            return;
        }
        //Else add the order to the end of the order list.
        Order current = head;
        while(current.next != null){
            current = current.next;
        }
        current.next = newOrder;
        end = newOrder;
        observer.update();
    }

    //Returns the last Order/Node.
    public Order getEnd(){return end;}
    //Attaching an observer and calling observer functions.
    public void attach(Observer observer){ this.observer = observer;}
    public void display(){observer.showInfo();}
    public float getTotal(){ return observer.getTotal();}
    public Restaurant getHighestProfit(){return observer.getHighestProfit();}
}
