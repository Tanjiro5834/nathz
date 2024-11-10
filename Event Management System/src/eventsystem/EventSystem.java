package eventsystem;
import java.util.HashMap;
import java.util.Map;
import java.util.List;
import java.util.LinkedList;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.UUID;
import java.time.*;
import java.time.format.DateTimeFormatter;
import java.util.Collections;

enum TicketType{
	STANDARD,
	VIP,
	EARLYBIRD,
	GROUPTICKET,
	STUDENT_DISCOUNTED,
	SEASON_PASS,
	ONLINE
}

enum EventTheme{
	CONFERENCE,
    WORKSHOP,
    SEMINAR,
    WEBINAR
}

public class EventSystem {
	static Map<String, Byte> attendeeCode = new HashMap<>();
	static List<Attendee_Details> attendeeList = new ArrayList<>();
	static List<TicketType> ticketType = new LinkedList<>();
	static LinkedList<EventTheme> eventTheme = new LinkedList<>();
	static Map<TicketType, String> ticketCodes = new HashMap<>();
	
	static List<Event_Details> events = new ArrayList<>();
	static Map<String, Integer> attendeeSeats = new HashMap<>();
	static List<String> eventCategory = new ArrayList<>();
	
	static Event_Details details;
	static Attendee_Details attendeeDetails;
	static int[] seats = new int[100];
	
	
	static Map<Attendee_Details,Integer> indexPairs= new HashMap<>();
	public static void main(String[] args) {
		var scan = new Scanner(System.in);
		System.out.println("""
			    1. Book an event
			    2. Attendee registration
			    3. Attendee seating arrangement
			    4. Attendance tracker
			    5. Search for an event or attendee
			""");
		
		printLines();
		
		while(true){
			System.out.print("Select option or enter '0' to exit: ");
			byte choice = scan.nextByte();
			scan.nextLine(); //clear buffer
			
			switch(choice) {
			case 1:
				System.out.print("Enter event: ");
				String event = scan.nextLine();
				
				System.out.print("Enter schedule for '" + event +  "': ");
				String schedule = scan.nextLine();
				
				System.out.print("Location: ");
				String location = scan.nextLine();
				
				System.out.print("Theme of the event: ");
				String theme = scan.nextLine();
				
				System.out.print("Time: ");
				String time = scan.nextLine();
				
				if(!event.isEmpty() && !schedule.isEmpty()){
					details = new Event_Details(event, schedule, location, theme, time);
					events.add(details);
				}else{
					System.out.println("Enter the event and the schedule.");
				}
				printLines();
				break;
				
			case 2:
				printLines();
				System.out.print("Enter attendee's name: ");
				String name = scan.nextLine();
				
				System.out.print("Ticket type: ");
				String ticket = scan.nextLine();
				
				System.out.print("Ticket code: ");
				String code = scan.nextLine();
				
				for(TicketType t : ticketType){
					if(ticket.equals(t)){
						for(Map.Entry<TicketType, String> e : ticketCodes.entrySet()){
							if(e.getValue().equals(code)){
								attendeeCode.put(name, Byte.parseByte(code));
								attendeeDetails = new Attendee_Details(name, ticket, code);
								
								attendeeList.add(attendeeDetails);
								System.out.println("Attendee added.");
								break;
							}else {
								System.out.println("The code is not valid.");
							}
						}
					}
				}
				break;
				
			case 3:
				printLines();
				System.out.print("Enter attendee name, ticket type, and code separated with spaces: ");
				String input = scan.nextLine();
				String[] values = input.split(" ");
				
				String attendee = values[0];
				String tType = values[1];
				byte tCode = Byte.parseByte(values[2]);
				
				for(Map.Entry<TicketType, String> e : ticketCodes.entrySet()) {
					if(e.getValue().equals(String.valueOf(tCode))) {
						initializeSeats();
						
						System.out.print("Select a seat for the attendee: ");
						byte prefferedSeats = scan.nextByte();
						
						if(prefferedSeats > 0){
							int[] updatedSeats = new int[seats.length - 1];
							for(int i = 0, j = 0; j < seats.length; j++) {
								if(j != prefferedSeats){
									updatedSeats[j++] = seats[i]; //remove the chosen seat from the list and assign in the map 
								}
							}
							attendeeSeats.put(attendee, (int) prefferedSeats);
							
							printLines();
							
							for(Map.Entry<String, Integer> entry : attendeeSeats.entrySet()){
								System.out.println("Attendee Name: " + entry.getKey() + ", Seat number: " + entry.getValue());
							}
						}
					}
				}
				
				System.out.println();
				sortList(attendeeSeats);
				break;
				
			case 4:
				boolean found = false, asPresent = false;
				
				for(Attendee_Details attendees : attendeeList){
					System.out.println(attendees.toString());
				}
				
				System.out.println();
				
				System.out.print("Enter name to mark as present or 'x' to mark as absent: ");
				String inputName = scan.nextLine();
				
				for(Attendee_Details at : attendeeList){
					if(inputName.equals(at.getAttendeeName())){
						found = true;
						System.out.println(inputName + " - " + asPresent != null ? true : false);
					}else{
						System.out.println("Attendee not found.");
					}
				}
				
				break;
				
			case 5:
				System.out.print("Enter your query: ");
				String query = scan.nextLine();
				
				boolean target = false;
				for(Event_Details e : events){
					if(e.getEvent().equalsIgnoreCase(query)){
						printLines();
						System.out.println("Event details: ".concat(e.toString()));
						target = true;
						break;
					}
				}
				
				if(!target){
					for(Attendee_Details at : attendeeList){
						if(at.getAttendeeName().equals(query)){
							printLines();
							System.out.println("Attendee details: ".concat(at.toString()));
							target = true;
							break;
						}
					}
				}
				
				if(!target) System.out.println("No matching queries.");
				break;
				
			default:
				System.out.println("Input invalid. Try again.");
				break;
			}
			
			if(choice == 0){
				System.out.println("Exiting the program...");
				break;
			}
		}
	}
	
	static void printLines(){
		for(int lines = 0; lines < 3; ++lines) System.out.println();
	}
	
	void initializeTicketsValues() {
		ticketType.add(TicketType.STANDARD);
		ticketType.add(TicketType.VIP);
		ticketType.add(TicketType.SEASON_PASS);
		ticketType.add(TicketType.ONLINE);
		ticketType.add(TicketType.GROUPTICKET);
		ticketType.add(TicketType.EARLYBIRD);
		ticketType.add(TicketType.STUDENT_DISCOUNTED);
		
		for(TicketType tType : ticketType){
			String code = UUID.randomUUID().toString().substring(0, 10);
			ticketCodes.put(tType, code);
		}
	}
	
	static void initializeSeats() {
		for(int nums = 0; nums < seats.length; nums++){
			seats[nums] = nums + 1;
			System.out.print(seats[nums]);
			if(nums < seats.length - 1) System.out.print(", ");
		}
	}
	
	static void sortList(Map<String,Integer> attendeeSeats){
		//sort the keys
		List<Map.Entry<String, Integer>> entries = new ArrayList<>(attendeeSeats.entrySet());
		int n = entries.size();
		for(int i = 0; i < n - 1; i++){
			int min = i;
			for(int j = i + 1; j < n; j++){
				if(entries.get(j).getKey().compareTo(entries.get(min).getKey()) < 0) min = j;
			}
			Collections.swap(entries, i, min);
		}
		
		//sort the values
		for(int i = 0; i < n - 1; i++){
			int min = i;
			for(int j = i + 1; j < n; j++) {
				if(entries.get(j).getValue() < entries.get(min).getValue()) min = j;
			}
			Collections.swap(entries, i, min);
		}
		 
		System.out.println("Arranged names and seats based on their selected seat:");
		printLines();
		for(Map.Entry<String, Integer> entry : entries){
            System.out.println(entry.getKey() + ", " + entry.getValue());
        }
	}
}

class Attendee_Details{
	private String name;
	private String ticket;
	private String code;
	
	public Attendee_Details(String n, String t, String c){
		this.name = n;
		this.ticket = t;
		this.code = c;
	}
	
	public String getAttendeeName() {return name;}
	public String getTicket() {return ticket;}
	public String getCode() {return code;}
	
	@Override
	public String toString() {
		return "Attendee name: " + name + "\nTicket type: " + ticket + "\nCode: " + code;
	}
}

class Event_Details{
	private String eventName;
	private LocalDate schedule;
	private String location;
	private String theme;
	private String time;
	
	public Event_Details(String en, String sched, String loc, String t, String time) {
		this.eventName = en;
		this.location = loc;
		this.theme = t;
		this.time = time;
		if(sched != null && !sched.isEmpty()){
            DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd");
            this.schedule = LocalDate.parse(sched, formatter);
        } else {
            this.schedule = null;
        }
	}
	
	public String getEvent() {return eventName;}
	public String getLocation() {return location;}
	public String getTheme() {return theme;}
	public String getTime() {return time;}
	
	public void setEvent(String e) {eventName = e;}
	
	public Event_Details setSchedule(String schedule) {
		DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy-MM-dd");
		this.schedule = LocalDate.parse(schedule, dtf);
		return this;
	}
}
