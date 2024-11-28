package src;
import javax.swing.*;
import java.awt.event.*;
import java.awt.Font;

class wordCounter {
	public static void main(String args[]) {
		JFrame f = new JFrame("Word Counter");
		JLabel l2, l3, l4, l5;
		JTextArea text;
		JLabel l1;
		JButton submit, clear;
		text = new JTextArea("");
		submit = new JButton("SUBMIT");
		clear = new JButton("CLEAR");
		l1 = new JLabel("Enter Your string Here : ");
		l2 = new JLabel("Consonants: ");
		l3 = new JLabel("Vowels: ");
        l4 = new JLabel("Words : ");
        l5 = new JLabel("Special Characters: ");
		
		Font txtFont = new Font(Font.SERIF, Font.PLAIN, 16);
		l1.setFont(txtFont);
		l2.setFont(txtFont);
		l3.setFont(txtFont);
		l4.setFont(txtFont);
		l1.setBounds(10, 25, 200, 30);
		text.setBounds(18, 60, 450, 300);
		l2.setBounds(10, 370, 400, 30);
		l3.setBounds(10, 400, 400, 30);
		l4.setBounds(10, 430, 400, 30);
		submit.setBounds(100, 470, 100, 50);
		clear.setBounds(275, 470, 100, 50);
		text.setLineWrap(true);
		text.setWrapStyleWord(true);
		submit.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
                int vowels = 0, consonants = 0, spc = 0;

                String cPattern = "[bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ]";

				String txt = text.getText().toLowerCase();
                String[] words = txt.split("\\s+");

                int wordCount = words.length; //get length

                for(char c : txt.toCharArray()){
                    if(Character.isLetter(c)){
                        if("aeiou".indexOf(c) >= 0){
                            vowels++;
                        }else{
                            consonants++;
                        }
                    }else if(!Character.isWhitespace(c)){
                        spc++;
                    }
                }

                l2.setText("Consonants: " + consonants);
                l3.setText("Vowels: " + vowels);
                l4.setText("Words: " + wordCount);
                l5.setText("Special Characters: " + spc);
			}
		});

		clear.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				text.setText("");
				l2.setText("Consonants: ");
                l3.setText("Vowels: ");
                l4.setText("Words: ");
                l5.setText("Special Characters: ");
			}
		});

		f.add(l1);
		f.add(text);
		f.add(l2);
		f.add(l3);
		f.add(l4);
		f.add(submit);
		f.add(clear);
		f.setSize(500, 570);
		f.setResizable(false);
		f.setLayout(null);
		f.setLocationRelativeTo(null);
		f.setVisible(true);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}