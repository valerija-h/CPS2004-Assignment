package Observer;

import Object.AllOrderLists;
import Object.OrderList;
import Object.Restaurant;

//Keeps track of the overall spent and highest profit restaurant of all the order lists.
public class AllOrderListsObserver extends Observer {
    private float total = 0;
    private Restaurant highestProfit; //The restaurant with the highest profit of all the order lists.
    private AllOrderLists orderLists;

    public AllOrderListsObserver(AllOrderLists OrderLists){
        this.orderLists = OrderLists;
        this.orderLists.attach(this);
        this.highestProfit = new Restaurant(null,null);
    }

    @Override
    public void update(){
        //Obtains the latest added order list.
        OrderList newOrderList = orderLists.getLastOrderList();
        Restaurant newOrderHighest = newOrderList.getHighestProfit();
        //Displays the information of the latest order list.
        System.out.println("Added a new order list with a total of: " + newOrderList.getTotal() + "€.");
        //Updates the highest revenue restaurant (if applicable) and the overall spent of all the order lists.
        total += newOrderList.getTotal();
        if(newOrderHighest.getProfit() > highestProfit.getProfit()){
            highestProfit = newOrderHighest;
        }
    }

    @Override
    public void showInfo() {
        //Displays the the overall price of all order lists and the restaurant with the highest profit.
        System.out.println("--------------------------------------------------------------------------");
        System.out.println("The highest revenue restaurant is '"+highestProfit.getRestaurantName() + "' with a total revenue of "+highestProfit.getProfit()+"€.");
        System.out.println("The total price all order lists is "+total+"€.");
    }

    @Override
    public float getTotal(){return total;}

    @Override
    public Restaurant getHighestProfit(){return highestProfit;}
}
