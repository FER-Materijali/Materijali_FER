package hr.fer.wim.flowerpower;

import android.app.Activity;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.util.TypedValue;
import android.view.Gravity;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;

public class InfoActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        LinearLayout layout = new LinearLayout(this);
        layout.setOrientation(LinearLayout.VERTICAL);

        LinearLayout.LayoutParams layoutParams = new LinearLayout.LayoutParams(700, 400);
        layoutParams.gravity=Gravity.CENTER;
        layoutParams.setMargins(0, 150, 0, 0);
        LinearLayout.LayoutParams layoutParamsText = new LinearLayout.LayoutParams(ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.WRAP_CONTENT);
        layoutParamsText.gravity = Gravity.CENTER;
        layoutParamsText.setMargins(0, 0, 0, 30);

        ImageView logo = new ImageView(this);
        logo.setImageResource(R.drawable.logo);
        logo.setLayoutParams(layoutParams);
        layout.addView(logo);

        TextView appName = new TextView(this);
        appName.setText(R.string.app_name);
        appName.setLayoutParams(layoutParamsText);
        appName.setTextSize(TypedValue.COMPLEX_UNIT_SP, 28);
        layout.addView(appName);

        TextView address = new TextView(this);
        address.setText(R.string.address);
        address.setLayoutParams(layoutParamsText);
        address.setTextSize(TypedValue.COMPLEX_UNIT_SP, 26);
        address.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(Intent.ACTION_VIEW, Uri.parse("geo:0,0?q=Unska 3, Zagreb"));
                startActivity(intent);
            }
        });
        layout.addView(address);

        TextView phoneNumber = new TextView(this);
        phoneNumber.setText(R.string.phone_number);
        phoneNumber.setLayoutParams(layoutParamsText);
        phoneNumber.setTextSize(TypedValue.COMPLEX_UNIT_SP, 22);
        phoneNumber.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent();
                intent.setAction(Intent.ACTION_DIAL);
                intent.setData(Uri.parse("tel:" + getResources().getString(R.string.phone_number)));
                startActivity(intent);
            }
        });
        layout.addView(phoneNumber);

        TextView email = new TextView(this);
        email.setText(getResources().getString(R.string.email, getResources().getString(R.string.email_address)));
        email.setLayoutParams(layoutParamsText);
        email.setTextSize(TypedValue.COMPLEX_UNIT_SP, 18);
        email.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(Intent.ACTION_SENDTO, Uri.fromParts(
                        "mailto", getResources().getString(R.string.email_address), null));
                intent.putExtra(Intent.EXTRA_SUBJECT, "Query from Flower power mobile app");
                startActivity(intent);
            }
        });
        layout.addView(email);

        TextView webPage = new TextView(this);
        webPage.setText(R.string.web_page);
        webPage.setLayoutParams(layoutParamsText);
        webPage.setTextSize(TypedValue.COMPLEX_UNIT_SP, 18);
        layout.addView(webPage);

        TextView author = new TextView(this);
        author.setText(R.string.author_name);
        author.setLayoutParams(layoutParamsText);
        author.setTextSize(TypedValue.COMPLEX_UNIT_SP, 18);
        layout.addView(author);

        this.setContentView(layout);
    }
}
