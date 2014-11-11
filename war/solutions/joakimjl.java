/*
# @EXPECTED_RESULTS@: CORRECT
*/

import java.util.*;

public class joakimjl {
    private static ArrayList<Integer> playerOneCards = new ArrayList<Integer>();
    private static ArrayList<Integer> playerTwoCards = new ArrayList<Integer>();
    private static int roundNumber = 0;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int playerOneNCards = in.nextInt();
        int playerTwoNCards = in.nextInt();

        for(int i = 0; i < playerOneNCards; i++){
            playerOneCards.add(in.nextInt());
        }

        for(int i = 0; i < playerTwoNCards; i++){
            playerTwoCards.add(in.nextInt());
        }

        while(true){
            if(roundNumber>= 100000){
                playerOneCards.clear();
                playerTwoCards.clear();
                printWinner();
                break;
            }

            if(playerOneCards.size() == 0 || playerTwoCards.size() == 0){
                printWinner();
                break;
            }

            int playerOneCard = playerOneCards.remove(0);
            int playerTwoCard = playerTwoCards.remove(0);

            if(playerOneCard > playerTwoCard){
                playerOneCards.add(playerOneCard);
                playerOneCards.add(playerTwoCard);
            }else if(playerOneCard < playerTwoCard){
                playerTwoCards.add(playerTwoCard);
                playerTwoCards.add(playerOneCard);
            }else {
                ArrayList<Integer> playerOnePool = new ArrayList<Integer>();
                ArrayList<Integer> playerTwoPool = new ArrayList<Integer>();

                playerOnePool.add(playerOneCard);
                playerTwoPool.add(playerTwoCard);
                war(playerOnePool, playerTwoPool);
            }
            roundNumber++;
        }
    }

    private static void war(ArrayList<Integer> playerOnePool, ArrayList<Integer> playerTwoPool){
        if(playerOneCards.size() < 4 || playerTwoCards.size() < 4){
            printWinner();
        }

        for(int i = 0; i < 3; i++){
            playerOnePool.add(playerOneCards.remove(0));
            playerTwoPool.add(playerTwoCards.remove(0));
        }

        int playerOneCard = playerOneCards.remove(0);
        int playerTwoCard = playerTwoCards.remove(0);

        playerOnePool.add(playerOneCard);
        playerTwoPool.add(playerTwoCard);

        if(playerOneCard == playerTwoCard){
            war(playerOnePool, playerTwoPool);
        }else if(playerOneCard > playerTwoCard){
            playerOneCards.addAll(playerOnePool);
            playerOneCards.addAll(playerTwoPool);
        }else {
            playerTwoCards.addAll(playerTwoPool);
            playerTwoCards.addAll(playerOnePool);
        }

    }

    private static void printWinner(){
        if(playerOneCards.size() == playerTwoCards.size()){
            System.out.println("draw");
        } else if(playerOneCards.size() > playerTwoCards.size()){
            System.out.println("you");
        }else {
            System.out.println("mike");
        }

        System.exit(0);
    }
}