package wdx.java.study;

import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Date;

/**
 * 回调是一种常见的程序设计模式。在这种模式中，可以指出某个特定事件发生时应采取的动作
 * @author wangda
 * @version v1.0 2013-10-28
 */
public class TimePrinter implements ActionListener
{

	@Override
	public void actionPerformed(ActionEvent e) {
		Date now = new Date();
		System.out.println("At the tone, the time is " + now);
		Toolkit.getDefaultToolkit().beep();
		
	}

}
