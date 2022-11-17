package hr.fer.wim.flowerpower;

import java.io.Serializable;
import java.util.*;

class Category implements Comparable<Category>, Serializable {
    Integer id;
    String name;
    String imgName;

    public Category(Integer id, String name, String imgName) {
        this.id = id;
        this.name = name;
        this.imgName = imgName;
    }

    public Integer getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public String getImgName() {
        return imgName;
    }

    @Override
    public int compareTo(Category o) {
        return this.id.compareTo(o.id);
    }
}

class Product implements Comparable<Product>, Serializable {
    Integer id;
    String name;
    Integer price;
    String imageUrl;

    public Product(Integer id, String name, Integer price, String imageUrl) {
        this.id = id;
        this.name = name;
        this.price = price;
        this.imageUrl = imageUrl;
    }

    public Integer getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public Integer getPrice() {
        return price;
    }

    public String getImageUrl() {
        return imageUrl;
    }

    @Override
    public int compareTo(Product o) {
        return this.id.compareTo(o.id);
    }
}

public class Utils {

    public static Map<Category, List<Product>> loadData() {

        Map<Category, List<Product>> data = new TreeMap<>();

        Category c1 = new Category(1, "Flowers", "img1_flowers");
        Category c2 = new Category(2, "Tools","img2_tools");
        Category c3 = new Category(3, "Pots","img3_pots");
        Category c4 = new Category(4, "Seed","img4_seeds");
        Category c5 = new Category(5, "Soil","img5_soil");
        Category c6 = new Category(6, "Fertilizers","img6_fertilizers");
        Category c7 = new Category(7, "Bird feeders","img7_feeders");
        Category c8 = new Category(8, "Garden gnomes","img8_gnomes");

        Product p1 = new Product(1, "Tulip", 10, "https://i.imgur.com/Ttir6mp.jpg");
        Product p2 = new Product(2, "Lavender", 15, "https://i.imgur.com/gH33WyT.jpg");
        Product p3 = new Product(3, "Fucsia", 50, "https://i.imgur.com/s27QJBL.jpg");
        Product p4 = new Product(4, "Daisy", 30, "https://i.imgur.com/Agarl4v.jpg");

        List<Product> pc1 = new ArrayList<Product>();
        pc1.add(p1); pc1.add(p2); pc1.add(p3); pc1.add(p4);

        Product p5 = new Product(5, "Shovel", 150, "https://i.imgur.com/BcjgzeT.jpg");
        Product p6 = new Product(6, "Small shovel", 50, "https://i.imgur.com/L80eL1e.jpg");
        Product p7 = new Product(7, "Rake", 10, "https://i.imgur.com/I5ctUan.jpg");

        List<Product> pc2 = new ArrayList<Product>();
        pc2.add(p5); pc2.add(p6); pc2.add(p7);

        Product p8 = new Product(8, "Tulip (1kg)", 200, "https://i.imgur.com/WUYYzBG.jpg");
        List<Product> pc4 = new ArrayList<Product>();
        pc4.add(p8);

        data.put(c1, pc1);
        data.put(c2, pc2);
        data.put(c3, new ArrayList<Product>());
        data.put(c4, pc4);
        data.put(c5, new ArrayList<Product>());
        data.put(c6, new ArrayList<Product>());
        data.put(c7, new ArrayList<Product>());
        data.put(c8, new ArrayList<Product>());

        return data;
    }


}
