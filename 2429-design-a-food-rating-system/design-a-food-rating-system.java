class FoodRatings {
    private static class Food implements Comparable<Food> {
        String name;
        int rating;

        Food(String name, int rating) {
            this.name = name;
            this.rating = rating;
        }

        @Override
        public int compareTo(Food other) {
            if (this.rating != other.rating) {
                return other.rating - this.rating; // higher rating first
            }
            return this.name.compareTo(other.name); // lexicographically smaller first
        }

        @Override
        public boolean equals(Object obj) {
            if (!(obj instanceof Food)) return false;
            Food f = (Food) obj;
            return this.name.equals(f.name) && this.rating == f.rating;
        }

        @Override
        public int hashCode() {
            return Objects.hash(name, rating);
        }
    }    

    private Map<String, String> foodToCuisine; // food -> cuisine
    private Map<String, Integer> foodToRating; // food -> rating
    private Map<String, TreeSet<Food>> cuisineFoods; // cuisine -> sorted foods

    public FoodRatings(String[] foods, String[] cuisines, int[] ratings) {
         foodToCuisine = new HashMap<>();
        foodToRating = new HashMap<>();
        cuisineFoods = new HashMap<>();

        for (int i = 0; i < foods.length; i++) {
            String food = foods[i];
            String cuisine = cuisines[i];
            int rating = ratings[i];

            foodToCuisine.put(food, cuisine);
            foodToRating.put(food, rating);

            cuisineFoods.putIfAbsent(cuisine, new TreeSet<>());
            cuisineFoods.get(cuisine).add(new Food(food, rating));
        }
    
    }
    
    public void changeRating(String food, int newRating) {
        String cuisine = foodToCuisine.get(food);
        int oldRating = foodToRating.get(food);

        TreeSet<Food> set = cuisineFoods.get(cuisine);
        // remove old food entry
        set.remove(new Food(food, oldRating));

        // add new food entry
        set.add(new Food(food, newRating));

        // update rating
        foodToRating.put(food, newRating);
    

    }
    
    public String highestRated(String cuisine) {
          return cuisineFoods.get(cuisine).first().name;
    }
}

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings obj = new FoodRatings(foods, cuisines, ratings);
 * obj.changeRating(food,newRating);
 * String param_2 = obj.highestRated(cuisine);
 */