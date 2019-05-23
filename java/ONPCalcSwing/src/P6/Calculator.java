package P6;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.Stack;
import java.util.StringTokenizer;


public class Calculator {

    private JButton showMsgBtn;
    private JPanel panelMain;
    private JTextField inputBufferTop;
    private JProgressBar progressBar;
    private JTextField inputBufferBottom;
    private JButton ONPButton;
    private JButton a7Button;
    private JButton a2Button;
    private JButton a3Button;
    private JButton button6;
    private JButton CEButton;
    private JButton a4Button;
    private JButton a8Button;
    private JButton a9Button;
    private JButton button10;
    private JButton a5Button;
    private JButton a6Button;
    private JButton button13;
    private JButton a1Button;
    private JButton a0Button;
    private JButton button15;
    private JButton button16;
    private JButton button17;
    private JButton button18;

    private Calculator() {
        inputBufferTop.setEditable(false);
        inputBufferBottom.setEditable(false);
        inputBufferTop.setFocusable(true);

        progressBar.setValue(0);
        progressBar.setStringPainted(true);

        for (Component comp : panelMain.getComponents()) {
            if (comp instanceof JButton) {
                comp.setFocusable(false);

                if (!((JButton) comp).getText().equals("CE") && !((JButton) comp).getText().equals("ONP") && !((JButton) comp).getText().equals("=")) {
                    ((JButton) comp).addActionListener(e -> {
                        String strFromTextField = inputBufferTop.getText();
                        inputBufferTop.setText(strFromTextField + e.getActionCommand());
                    });
                }
                ((JButton) comp).addActionListener(e -> {
                    int str = progressBar.getValue();
                    progressBar.setValue(str + 1);
                });
            }
        }

//        Action ax = new AbstractAction() {
//            public void actionPerformed(ActionEvent e) {
//                  clearBuffer();
//            }
//        };

        CEButton.addActionListener(e -> clearBuffer());

//        CEButton.getInputMap(JComponent.WHEN_IN_FOCUSED_WINDOW).put(KeyStroke.getKeyStroke("F2"), "BS");
//        CEButton.getActionMap().put("BS", ax);


        inputBufferTop.addKeyListener(new KeyAdapter() {
            @Override
            public void keyTyped(KeyEvent e) {
                super.keyTyped(e);
                String strFromTextField = inputBufferTop.getText();
                inputBufferTop.setText(strFromTextField + e.getKeyChar());

                if(e.getKeyChar() == KeyEvent.VK_ENTER){
                    getONP();
                }
            }

            @Override
            public void keyReleased(KeyEvent e) {
                super.keyReleased(e);
                int str = progressBar.getValue();
                if (str == 50)
                    System.exit(0);
                progressBar.setValue(str + 1);

                if (e.getKeyCode() == KeyEvent.VK_BACK_SPACE) {
                    clearBuffer();
                }
                else if(e.getKeyCode() == KeyEvent.VK_ENTER){
                    getCalculateONP();
                }
            }
        });
        ONPButton.addActionListener(e -> getONP());

        button18.addActionListener(e -> getCalculateONP());

    }//calculator

    private void clearBuffer() {
        inputBufferTop.setText("");
        inputBufferBottom.setText("");
        progressBar.setValue(0);
    }
    private void getCalculateONP(){
        String strFromBuff = inputBufferBottom.getText();
        double result = calculateONP(strFromBuff);
        inputBufferBottom.setText("");
        inputBufferBottom.setText(Double.toString(result));
    }
    private void getONP() {
        String inputBuff = inputBufferTop.getText();
        String strToCalculate = getONPString(inputBuff);
        inputBufferBottom.setText(strToCalculate);
    }

    private String getONPString(String inputBuff) {
        Stack<String> stack = new Stack<>();
        StringTokenizer token = new StringTokenizer(inputBuff, "+-*/()", true);//1
        String onpBuff = "";
        while (token.hasMoreTokens()) {
            String s = token.nextToken();
            if (s.equals("+") || s.equals("*") || s.equals("-") || s.equals("/")) {
                while (!stack.empty() && prior(stack.peek()) >= prior(s))
                    onpBuff += stack.pop() + " ";
                stack.push(s);
            } else if (s.equals("(")) {
                stack.push(s);
            } else if (s.equals(")")) {
                while (!stack.peek().equals("(")) {
                    onpBuff += stack.pop() + " ";
                }
                stack.pop();
            } else {
                onpBuff += s + " ";
            }

        }
        while (!stack.empty()) {
            onpBuff += stack.pop() + " ";//3.1
        }
        return onpBuff;
    }

    private int prior(String op) {
        switch (op) {
            case "+":
            case "-":
                return 1;
            case "*":
            case "/":
                return 2;
            case "^":
                return 3;
            default:
                return 0;
        }
    }

    private double calculateONP(String onp) {

        String out = onp + " =";
        Stack<Double> stack = new Stack<>();

        double a;
        double b;
        double result = 0;

        String build = "";
        char space = ' ';
        int it = 0;

        do {
            char ch = out.charAt(it);
            if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                if (!stack.empty()) {
                    b = stack.pop();
                    a = stack.pop();

                    if (ch == '+') result = a + b;
                    else if (ch == '-') result = a - b;
                    else if (ch == '*') result = a * b;
                    else result = a / b;
                    stack.push(result);
                }
            } else if (ch == space) {
                if (build.compareTo("") != 0) {
                    double tmp = Double.parseDouble(build);
                    stack.push(tmp);
                    build = "";
                }
            } else if (ch == '=') {
                if (!stack.empty()) {
                    result = stack.pop();
                    break;
                }
            } else if (ch >= '0' && ch <= '9') {
                build += ch;
            }
            it++;
        } while (it < out.length());

        return result;
    }

    public static void main(String[] args) {
        JFrame frame = new JFrame("Calc");
        frame.setContentPane(new Calculator().panelMain);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 500);
        frame.setVisible(true);
        frame.setResizable(false);
    }

}
