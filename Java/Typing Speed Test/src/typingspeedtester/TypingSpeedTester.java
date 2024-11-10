
package typingspeedtester;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Random;

public class TypingSpeedTester extends JFrame {

    private JTextArea textArea;
    private JTextField inputField;
    private JButton startButton;
    private JLabel timerLabel;
    private JLabel wpmLabel;
    private Timer timer;
    private int timeInSeconds;
    private int wpm;
    private String currentSentence;
    
    public TypingSpeedTester(String title){
        super(title);
        setLayout(new BorderLayout());
        
        textArea = new JTextArea("Type text here...", 10, 30);
        textArea.setEditable(true);
        
        inputField = new JTextField(30);
        startButton = new JButton("Start test");
        startButton.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                startTest();
            }
        });
        
         timerLabel = new JLabel("Time: 0s");
         wpmLabel = new JLabel("WPM: 0");
                
        add(new JScrollPane(textArea), BorderLayout.CENTER);
        add(inputField, BorderLayout.SOUTH);
        add(startButton, BorderLayout.SOUTH);
        add(timerLabel, BorderLayout.NORTH);

        timer = new Timer(1000, new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                update();
            }
        });
    }
    
    private void startTest(){
        timeInSeconds = 0;
        timer.start();
        currentSentence = generateRandomSentence();
        textArea.setText(currentSentence);
        textArea.setEditable(true);
        inputField.requestFocus();
    }
    
    private void update(){
        timeInSeconds++;
        timerLabel.setText("Time: "+timeInSeconds+"s");
        updatewpm();
    }
    
    private void updatewpm(){
        String sentence = inputField.getText();
        String[]words=sentence.split("\\s+");
        int typedWord = words.length;
        int WPM = (int) ((typedWord / 5.0) / (timeInSeconds / 60.0));
        
        wpmLabel.setText("WPM: "+WPM);
    }
    
    private static String generateRandomSentence(){
        String[] words = {"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog."};
        StringBuilder sentence = new StringBuilder();
        
        Random rand = new Random();
        int length = rand.nextInt(5)+5;
        for(int i = 0; i < length; i++){
            int wordIndex = rand.nextInt(words.length);
            sentence.append(words[wordIndex]).append(" ");
        }
        
        return sentence.toString().trim();
    }
    public static void main(String[] args) {
       SwingUtilities.invokeLater(() -> {
            TypingSpeedTester tester = new TypingSpeedTester("Typing Speed Tester");
            tester.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            tester.setSize(500, 300);
            tester.setVisible(true);
        });
    }
    
}
