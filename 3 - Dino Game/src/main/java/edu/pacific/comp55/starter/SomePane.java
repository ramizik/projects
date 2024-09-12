package edu.pacific.comp55.starter;
import java.awt.Color;
import java.awt.event.MouseEvent;

import acm.graphics.GRect;
import acm.graphics.GImage;
import acm.graphics.GObject;

public class SomePane extends GraphicsPane {
	private MainApplication program; // you will use program to get access to
										// all of the GraphicsProgram calls
	private GImage img;
	private GParagraph para;
	private GRect rec;

	public SomePane(MainApplication app) {
		this.program = app;
		img = new GImage("robot head.jpg", 100, 100);
		para = new GParagraph("welcome\nto my\nsecret room!", 150, 300);
		para.setFont("Arial-24");
		rec = new GRect(0, 0, 1000, 1000);
		rec.setFilled(true);
		rec.setFillColor(Color.blue);
		
		
	}

	@Override
	public void showContents() {
		program.add(rec);
		program.add(img);
		program.add(para);
	}

	@Override
	public void hideContents() {
		program.remove(img);
		program.remove(para);
	}

	@Override
	public void mousePressed(MouseEvent e) {
		para.setText("you need\nto click\non the eyes\nto go back");
		GObject obj = program.getElementAt(e.getX(), e.getY());
		if (obj == img) {
			program.switchToMenu();
		}
	}
}
