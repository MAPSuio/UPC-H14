/*
# @EXPECTED_RESULTS@: CORRECT
*/

import java.util.*;

public class joakimjl{
    static HashMap<String,Node> teams = new HashMap<String, Node>();

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        /* Create graph */
        while(in.hasNext()){
            String line[] = in.nextLine().split(" ");

            Node teamOne = getTeam(line[0]);
            Node teamTwo = getTeam(line[2]);

            if(line[1].equals("BEFORE")){
                teamOne.addOutgoing(teamTwo);
                teamTwo.addIncoming(teamOne);
            } else {
                teamOne.addIncoming(teamTwo);
                teamTwo.addOutgoing(teamOne);
            }
        }

        ArrayList<Node> noEdges = new ArrayList<Node>();

        /*Find nodes with no incoming edges */
        for(Node node : teams.values()){
            if(node.getIncoming().size() == 0){
                noEdges.add(node);
            }
        }

        ArrayList<Node> result = new ArrayList<Node>();

        while(!noEdges.isEmpty()){
            Node node = noEdges.remove(0);
            result.add(node);

            for(Node neighbour: node.getOutgoing()){
                neighbour.removeIncomingEdge(node);
                if(neighbour.getIncoming().size() == 0){
                    noEdges.add(neighbour);
                }
            }
        }
        printResult(result);
    }


    private static void printResult(ArrayList<Node> result){
        for(Node node: result){
            System.out.println(node.getName());
        }
    }

    private static Node getTeam(String name){
        Node team = teams.get(name);
        if(team == null){
            team = new Node(name);
            teams.put(name, team);
            return team;
        }else {
            return team;
        }
    }
}

class Node implements Comparable<Node> {
    private ArrayList<Node> outgoing = new ArrayList<Node>();
    private ArrayList<Node> incoming = new ArrayList<Node>();
    private String name;

    Node(String name){
        this.name = name;
    }

   public void addOutgoing(Node node){
       outgoing.add(node);
   }

    public void addIncoming(Node node){
        incoming.add(node);
    }

    public ArrayList<Node> getOutgoing() {
        return outgoing;
    }

    public ArrayList<Node> getIncoming(){
        return incoming;
    }

    public void removeIncomingEdge(Node node){
        incoming.remove(node);
    }

    public String getName(){
        return name;
    }

    @Override
    public int compareTo(Node o) {
        return this.getName().compareTo(o.getName());
    }
}
