package hr.fer.wim.flowerpower;

import android.app.Activity;
import android.app.SearchManager;
import android.content.Intent;
import android.os.Bundle;
import android.util.TypedValue;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;

import java.util.List;
import java.util.Map;

public class ProductListActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        Bundle extras = getIntent().getExtras();
        Category category = (Category) extras.getSerializable("category");
        LinearLayout layout = new LinearLayout(this);
        layout.setOrientation(LinearLayout.VERTICAL);

        Map<Category, List<Product>> categories = Utils.loadData();
        for (Map.Entry<Category, List<Product>> e : categories.entrySet()) {
            if (e.getKey().getName().equals(category.getName())) {
                TextView categoryName = new TextView(this);
                categoryName.setText(category.getName());
                categoryName.setTextSize(TypedValue.COMPLEX_UNIT_SP, 28);
                layout.addView(categoryName);
                for (final Product p: e.getValue()) {
                    LinearLayout lineLayout = new LinearLayout(this);
                    lineLayout.setOrientation(LinearLayout.HORIZONTAL);
                    lineLayout.setLayoutParams(new LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT, 0));
                    TextView productName = new TextView(this);
                    productName.setTextSize(TypedValue.COMPLEX_UNIT_SP, 20);
                    productName.setLayoutParams(new LinearLayout.LayoutParams(0, ViewGroup.LayoutParams.WRAP_CONTENT, 2));
                    productName.setText("  " + p.getName());
                    lineLayout.addView(productName);

                    Button plus = new Button(this);
                    plus.setText("+");
                    plus.setLayoutParams(new LinearLayout.LayoutParams(0, ViewGroup.LayoutParams.WRAP_CONTENT, 1));
                    plus.setOnClickListener(new View.OnClickListener() {
                        @Override
                        public void onClick(View v) {
                            Toast.makeText(ProductListActivity.this, R.string.toast_message, Toast.LENGTH_SHORT).show();
                        }
                    });
                    lineLayout.addView(plus);

                    Button info = new Button(this);
                    info.setText("INFO");
                    info.setLayoutParams(new LinearLayout.LayoutParams(0, ViewGroup.LayoutParams.WRAP_CONTENT, 1));
                    info.setOnClickListener(new View.OnClickListener() {
                        @Override
                        public void onClick(View v) {
                            Intent i = new Intent(Intent.ACTION_WEB_SEARCH);
                            i.putExtra(SearchManager.QUERY, p.getName());
                            startActivity(i);
                        }
                    });
                    lineLayout.addView(info);
                    layout.addView(lineLayout);
                }
            }
        }

        this.setContentView(layout);
    }
}
