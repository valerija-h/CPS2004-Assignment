import Object.AllOrderLists;
import Object.OrderList;
import Object.Restaurant;
import Observer.AllOrderListsObserver;
import Observer.OrderListObserver;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;

class ReadFile {
    //Stores all the restaurants from the file.
    private ArrayList<Restaurant> restaurants = new ArrayList<>();

    //This function reads from a given file and parses and executes each line.
    void execFile(String file){
        //Stores all the order lists and attaches an observer.
        AllOrderLists allOrderLists = new AllOrderLists();
        new AllOrderListsObserver(allOrderLists);

        //Creates a new buffer to read each line of the file.
        try (BufferedReader br = new BufferedReader(new FileReader(file))) {
            while (br.ready()) {
                String line = br.readLine();

                //Validation to remove empty lines and trim possible whitespaces.
                line = line.replace("\n", "").replace("\r", "").trim();
                if(line.length() == 0){ continue; }

                //Tokenizes the string to check for commands.
                String[] tokens = line.split("\\s+");

                //Creating a new order list.
                if(tokens[0].equals("BeginOrderList") && tokens.length == 1){
                    //Extracts the lines between BeginOrderList and EndOrderList.
                    ArrayList<String> temp = new ArrayList<>();
                    line = br.readLine();
                    while(!line.split("\\s+")[0].equals("EndOrderList")){
                        temp.add(line);
                        line = br.readLine();
                        if(line == null){ throw new Exception("Error execFile() - No EndOrderList was found."); }
                    }
                    //Creates an order list with the extracted lines then adds it to the array list of all order lists.
                    allOrderLists.addOrderList(addOrderList(temp));
                    continue;
                }

                //Creating a new restaurant.
                if(tokens[0].equals("BeginRestaurant") && tokens.length == 3){
                    //Extracts the restaurant name, delivery type and lines between BeginRestaurant and EndRestaurant.
                    String name = tokens[1];
                    String delivery = tokens [2];
                    ArrayList<String> temp = new ArrayList<>();
                    line = br.readLine();
                    while(!line.split("\\s+")[0].equals("EndRestaurant")){
                        temp.add(line);
                        line = br.readLine();
                        if(line == null){ throw new Exception("Error execFile() - No EndRestaurant was found."); }
                    }
                    //Creates a new restaurant with extracted lines then adds it to the array list of all restaurants.
                    restaurants.add(addRestaurant(name,delivery,temp));
                    continue;
                }

                throw new Exception("Error execFile() - Command '"+line+"' not Recognized.");
            }
        }catch (Exception e){
            e.printStackTrace();
        }
        //Displays the highest revenue restaurant and overall spent on all the order lists.
        allOrderLists.display();
    }

    //Creates and returns a restaurant object with a given name, delivery type and a string list of items.
    private Restaurant addRestaurant(String name, String delivery, ArrayList<String> items) throws Exception{
        //Create a temporary new restaurant object.
        Restaurant restaurant = new Restaurant(name,delivery);

        //Parses each line of the string array list of items and adds them to the restaurant item list.
        for(String item : items){
            //Ignores empty lines.
            if(item.length() == 0){ continue; }

            String[] tokens = item.split("\\s+");
            if(tokens[0].equals("Item") && tokens.length == 3) {
                //Adds a new item to the restaurant with a name and price.
                restaurant.addItem(tokens[1], Float.parseFloat(tokens[2]));
                continue;
            }
            throw new Exception("Error addRestaurant() - Command '" + item + "' not recognized.");
        }
        return restaurant;
    }

    //Creates and returns an order list with a given array list of commands.
    private OrderList addOrderList(ArrayList<String> input) throws Exception{
        //Creates a new order list and attaches an observer.
        OrderList orderList = new OrderList();
        new OrderListObserver(orderList);

        //Goes through each line of given input and creates orders.
        for (int i=0; i<input.size(); i++){
            ArrayList<String> order = new ArrayList<>();
            //Ignores empty lines.
            if(input.get(i).length() == 0){ continue; }
            String[] tokens = input.get(i).split("\\s+");

            //Creating a Order.
            if(tokens[0].equals("BeginOrder") && tokens.length == 3){
                i++;
                //Extracts the restaurant name, delivery type and lines between BeginOrder and EndOrder.
                String name = tokens[1];
                String delivery = tokens[2];
                while(!input.get(i).split("\\s+")[0].equals("EndOrder")){
                    if(i == input.size()-1){
                        System.out.println("Error addOrderList() - No EndOrder was found.");
                        System.exit(0);
                    }
                    order.add(input.get(i));
                    i++;
                }

                //Finds a restaurant matching the current order.
                Restaurant restaurant = findRestaurant(name,delivery);
                float profit = 0f; //Keeps track of money spent in the current order.

                //Parses and executes the lines between BeginOrder and EndOrder (the item orders).
                ArrayList<String> items = new ArrayList<>();
                for(String item : order){
                    if(item.length() == 0){ continue; }
                    String[] token = item.split("\\s+");
                    if(token[0].equals("OrderItem") && token.length == 2){
                        //Adds the item name to an array list and adds its price to the profits made in the current order.
                        items.add(token[1]);
                        profit += restaurant.getPrice(token[1]);
                        continue;
                    }
                    throw new Exception("Error addOrderList() - Command '" + order + "' not recognized.");
                }
                //Adds the overall profits of the current order to the matching restaurant.
                restaurant.addProfit(profit);
                //Adds the current order to the order list.
                orderList.addOrder(name,delivery,items,profit,restaurant);
                continue;
            }
            throw new Exception("Error addOrderList() - Command '" + input.get(i) + "' not recognized.");
        }
        return orderList;
    }


    //Finds and returns a restaurant with matching name and delivery type.
    private Restaurant findRestaurant(String name, String delivery) throws Exception{
        //Iterates through each restaurant in the restaurant array list and finds one with matching name and delivery type.
        for(Restaurant restaurant : restaurants){
            if(restaurant.getRestaurantName() == null){continue;}
            if(restaurant.getRestaurantName().equals(name) && (restaurant.getDeliveryType().equals(delivery) || restaurant.getDeliveryType().equals("both"))){
                return restaurant;
            }
        }
        throw new Exception("Error findRestaurant() - Restaurant with name '"+ name +"' and delivery type '"+ delivery +"' was not found.");
    }
}
