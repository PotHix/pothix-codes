package com.android.googleio2010bootcampcodelab;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

/**
 * Collects a search query from the user and calls ListData using an
 * Intent that contains EXTRA_TEXT.
 */
public class CollectData extends Activity implements View.OnClickListener {
    /** 
     * Called when the activity is first created. Sets our content view and adds
     * our onClickListener for the button.
     * @param savedInstanceState If the activity is being re-initialized after previously being shut down then this Bundle contains the data it most recently supplied in onSaveInstanceState(Bundle). Note: Otherwise it is null.
     * @see <a href="http://developer.android.com/reference/android/app/Activity.html#onCreate(android.os.Bundle)">Activity:onCreate</a>
     */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        /**
         * Step 02: Uncomment the following lines to find
         * the button and attach our class as its listener
         */
        Button bv = (Button)findViewById(R.id.ButtonGo);
        bv.setOnClickListener(this);
    }

    /**
     * The View.OnClickListener implementation. 
     * @see <a href="http://developer.android.com/reference/android/view/View.OnClickListener.html">View.OnClickListener</a>
     */
	public void onClick(View v) {
        /**
         * Step 03: Uncomment the following lines to handle
         * the event.
         * 
         * The following code checks to make sure that our "Go"
         * button was pressed -- which is not necessary, as it is
         * the only control that we have registered an onCLick
         * handler for.  But, this is a good pattern to allow us
         * to use a single onClick handler to handle events from
         * multiple views.  
         * 
         * It grabs the text from the EditText widget and adds it as text data
         * to the explicit intent that calls ListData.  It clears the
         * text from the widget, and starts the ListData activity.
         */
		switch ( v.getId() ) {
		case R.id.ButtonGo:
			Intent listDataIntent = new Intent(this, ListData.class);
			EditText et = (EditText)findViewById(R.id.EditTextQuery);
			String inputText = et.getText().toString();
			listDataIntent.putExtra(Intent.EXTRA_TEXT, inputText);
			et.setText("");
			startActivity(listDataIntent);
		}
	}
}