package Observer;
import Object.Restaurant;

public abstract class Observer {
    //Update the contents of the observer object.
    public abstract void update();
    //Display the contents of the observer object.
    public abstract void showInfo();
    //Return the total spent and highest revenue restaurant of the observer object.
    public abstract Restaurant getHighestProfit();
    public abstract float getTotal();
}
