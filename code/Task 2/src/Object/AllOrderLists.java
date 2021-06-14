package Object;
import Observer.Observer;

import java.util.ArrayList;

public class AllOrderLists {
    private ArrayList<OrderList> orderLists;
    private OrderList lastOrderList;
    private Observer observer;

    public AllOrderLists(){
        orderLists = new ArrayList<>();
    }

    //Adds a new OrderList and updates the observer.
    public void addOrderList(OrderList orderList){
        orderLists.add(orderList);
        lastOrderList = orderList;
        observer.update();
    }

    //Returns the last OrderList.
    public OrderList getLastOrderList() { return lastOrderList; }
    //Attaching an observer and calling observer functions.
    public void attach(Observer observer){ this.observer = observer; }
    public void display(){observer.showInfo();}
}
