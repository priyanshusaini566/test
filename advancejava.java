import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class studentform implements ActionListener {


    JFrame jFrame;
    JLabel l1,l2,l3,l4;
    JTextField name,email,rollno,section;
    JButton submit;

    studentform(){
        jFrame=new JFrame("student form");
        l1=new JLabel("student name");
        l2=new JLabel("student email");
        l3=new JLabel("student roll no.");
        l4=new JLabel("student section");

        name=new JTextField();
        email=new JTextField();
        rollno=new JTextField();

        submit=new JButton("Submit");

        l1.setBounds(50,50,100,30);
        name.setBounds(160,50,150,30);

        l2.setBounds(50,90,100,30);
        email.setBounds(160,90,150,30);

        l3.setBounds(50,140,100,30);
        rollno.setBounds(160,140,150,30);

        submit.setBounds(110,180,100,30);

        jFrame.add(l1);
        jFrame.add(name);
        jFrame.add(l2);
        jFrame.add(email);
        jFrame.add(l3);
        jFrame.add(rollno);
        jFrame.add(submit);
        submit.addActionListener(this);

        jFrame.setLayout(null);
        jFrame.setSize(400,300);
        jFrame.setVisible(true);
        jFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);


    }


    public static void main(String[] args) {
        new studentform();

    }

    @Override
    public void actionPerformed(ActionEvent e) {
        String name1 = name.getText();
        String email1 = email.getText();
        String roll=rollno.getText();


        JOptionPane.showMessageDialog(jFrame,"Student Name is : "+name1
                + "\nStudent Email is : "+email1+"\n Student Roll no. is : "+roll);
    }
}
