
package com.example.learnjni;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

public class MainActivity extends Activity{

	@Override
	protected void onCreate(Bundle savedInstanceState){
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

	}

	public void onBtnClick(View v){
		int id = v.getId();
		if(id == R.id.btn_1){
			Example.testJniLog();
		}

	}

	public void makeToast(String msg){
		Toast.makeText(this, msg, Toast.LENGTH_SHORT).show();
	}
	
	static{
		System.loadLibrary("learnjni");
	}
}
