package Observer;

import Object.Order;
import Object.OrderList;
import Object.Restaurant;

//Keeps track of the overall spent and highest profit restaurant of a single order list.
public class OrderListObserver extends Observer {
    private float total;
    private Restaurant highestProfit;
    private OrderList orderList;

    public OrderListObserver(OrderList orderList){
        this.orderList = orderList;
        this.orderList.attach(this);
        this.highestProfit = new Restaurant(null,null);
    }

    @Override
    public void update(){
        //Obtains the latest added order.
        Order newOrder = orderList.getEnd();
        Restaurant newOrderRestaurant = newOrder.getRestaurant();
        //Updates the total and the highest revenue restaurant (if applicable) for current order list.
        total += newOrder.getTotal();
        if(newOrderRestaurant.getProfit() > highestProfit.getProfit()){
            highestProfit = newOrderRestaurant;
        }
    }

    @Override
    public void showInfo(){
        //Displays the the overall spent and the highest revenue restaurant for the current order list.
        System.out.println("The highest revenue restaurant is '" + highestProfit.getRestaurantName() + "' with a total revenue of "+highestProfit.getProfit()+"€.");
        System.out.println("The total price all order lists is " + total + "€.");
    }

    @Override
    public float getTotal(){return total;}

    @Override
    public Restaurant getHighestProfit(){return highestProfit;}
}
