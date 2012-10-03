package com.android.googleio2010bootcampcodelab;

import android.os.Bundle;
import android.preference.PreferenceActivity;

/**
 * A simple PreferenceActivity class that executes the preferences described
 * in the search_preferences XML file.
 */
public class SearchPreferences extends PreferenceActivity {

    /** 
     * Called when the activity is first created. Adds the preferences from
     * the search_preferences XML file.
     * @param savedInstanceState If the activity is being re-initialized after previously being shut down then this Bundle contains the data it most recently supplied in onSaveInstanceState(Bundle). Note: Otherwise it is null.
     * @see <a href="http://developer.android.com/reference/android/app/Activity.html#onCreate(android.os.Bundle)">Activity:onCreate</a>
     */
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		addPreferencesFromResource(R.xml.search_preferences);
	}

}
