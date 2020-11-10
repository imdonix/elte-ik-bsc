package colorclicker;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import java.awt.Color;
import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.Point;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.Timer;

/**
 *
 * @author pinter
 */
public class BoardGUI {

    private JButton[][] buttons;
    private Board board;
    private JPanel boardPanel;
    private JLabel timeLabel;
    private ArrayList<Point> points;

    private Random random = new Random();
    private int clickNum = 0;
    private long startTime;
    private Timer timer;

    private final int NUM_COLORED_FIELDS = 4;

    public BoardGUI(int boardSize) {
        board = new Board(boardSize);
        boardPanel = new JPanel();
        points = new ArrayList<>();
        boardPanel.setLayout(new GridLayout(board.getBoardSize(), board.getBoardSize()));
        buttons = new JButton[board.getBoardSize()][board.getBoardSize()];
        for (int i = 0; i < board.getBoardSize(); ++i) {
            for (int j = 0; j < board.getBoardSize(); ++j) {
                JButton button = new JButton();
                button.addActionListener(new ButtonListener(i, j));
                button.setPreferredSize(new Dimension(80, 40));
                buttons[i][j] = button;
                boardPanel.add(button);
                points.add(new Point(i, j));
            }
        }
        Collections.shuffle(points);

        timeLabel = new JLabel(" ");
        timeLabel.setHorizontalAlignment(JLabel.RIGHT);
        timer = new Timer(10, new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                timeLabel.setText(elapsedTime() + " ms");
            }
        });
        startTime = System.currentTimeMillis();
        timer.start();
    }

    public long elapsedTime() {
        return System.currentTimeMillis() - startTime;
    }

    public void refresh(int x, int y) {
        JButton button = buttons[x][y];
        Field field = board.get(x, y);
        button.setBackground(field.getColor());
        if (field.getColor() != null) {
            button.setText(String.valueOf(field.getNumber()));
        } else {
            button.setText("");
        }
    }

    public JPanel getBoardPanel() {
        return boardPanel;
    }

    class ButtonListener implements ActionListener {

        private int x, y;

        public ButtonListener(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            if (board.get(x, y).getColor() == null) {
                Color color = new Color(random.nextInt(256),
                        random.nextInt(256), random.nextInt(256));
                board.get(x, y).setColor(color);
                board.get(x, y).setNumber(++clickNum);
                for (int i = 0; i < NUM_COLORED_FIELDS;) {
                    Point point = points.remove(points.size() - 1);
                    if (board.get(point).getColor() == null) {
                        board.get(point).setColor(color);
                        board.get(point).setNumber(clickNum);
                        refresh(point.x, point.y);
                        i++;
                    }
                }
                refresh(x, y);
                if (board.isOver()) {
                    timer.stop();
                    JOptionPane.showMessageDialog(boardPanel, "You have won in " + elapsedTime() + " ms.", "Congrats!",
                            JOptionPane.PLAIN_MESSAGE);
                }

            }
        }
    }

    public JLabel getTimeLabel() {
        return timeLabel;
    }

}
