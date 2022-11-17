package hr.fer.wim.flowerpower;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.Gravity;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.ScrollView;

import java.util.List;
import java.util.Map;

public class CategoryListActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        ScrollView scrollView = new ScrollView(this);
        LinearLayout layout = new LinearLayout(this);
        layout.setOrientation(LinearLayout.VERTICAL);

        Map<Category, List<Product>> categories = Utils.loadData();
        for (final Category c: categories.keySet()) {
            ImageView image = new ImageView(this);
            image.setImageResource(getResources().getIdentifier(c.getImgName(), "drawable", getPackageName()));
            LinearLayout.LayoutParams layoutParams = new LinearLayout.LayoutParams(300, 300);
            layoutParams.gravity= Gravity.CENTER;
            image.setLayoutParams(layoutParams);
            layout.addView(image);

            Button button = new Button(this);
            button.setText(c.getName());
            button.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    Intent i = new Intent(CategoryListActivity.this, ProductListActivity.class);
                    i.putExtra("category", c);
                    startActivity(i);
                }
            });
            layout.addView(button);
        }

        scrollView.addView(layout);
        this.setContentView(scrollView);
    }
}
