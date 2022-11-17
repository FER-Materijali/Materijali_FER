package hr.fer.wim.flowerpower;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.LinearLayout;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        LinearLayout layout = new LinearLayout(this);
        layout.setOrientation(LinearLayout.VERTICAL);
        LinearLayout.LayoutParams lp = new LinearLayout.LayoutParams(
                ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT);

        Button categories = new Button(this);
        categories.setText(R.string.product_categories);
        categories.setLayoutParams(lp);
        categories.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent i = new Intent(MainActivity.this, CategoryListActivity.class);
                startActivity(i);
            }
        });
        layout.addView(categories);

        Button info = new Button(this);
        info.setText("INFO");
        info.setLayoutParams(lp);
        info.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent i = new Intent(MainActivity.this, InfoActivity.class);
                startActivity(i);
            }
        });
        layout.addView(info);

        Button cjenik = new Button(this);
        cjenik.setText(R.string.price_list);
        cjenik.setLayoutParams(lp);
        cjenik.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(Intent.ACTION_VIEW);
                intent.setDataAndType(Uri.parse(getResources().getString(R.string.pdf_uri)), "application/pdf");
                startActivity(intent);
            }
        });
        layout.addView(cjenik);

        setContentView(layout);
    }
}