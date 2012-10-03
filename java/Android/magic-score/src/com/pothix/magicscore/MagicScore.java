package com.pothix.magicscore;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.TextView;

public class MagicScore extends Activity {
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        
        activateButtonsForPlayer((TextView)findViewById(R.id.player1), (Button)findViewById(R.id.player1_minus), (Button)findViewById(R.id.player1_plus));
        activateButtonsForPlayer((TextView)findViewById(R.id.player2), (Button)findViewById(R.id.player2_minus), (Button)findViewById(R.id.player2_plus));
    }
    
    private void activateButtonsForPlayer(final TextView player, Button minus, Button plus){

        plus.setOnClickListener(new OnClickListener() {	
			@Override
			public void onClick(View v) {
				player.setText(String.valueOf(Integer.parseInt(player.getText().toString()) + 1));
			}
		});
        
        
        minus.setOnClickListener(new OnClickListener() {	
			@Override
			public void onClick(View v) {
				player.setText(String.valueOf(Integer.parseInt(player.getText().toString()) - 1));
			}
		}); 
    }
}