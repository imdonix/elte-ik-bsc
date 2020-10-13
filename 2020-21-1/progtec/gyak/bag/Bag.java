/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package bag;

import java.util.ArrayList;

/**
 *
 * @author bli
 */
public class Bag {

    private final ArrayList<BagItem> data;

    public Bag() {
        this.data = new ArrayList<>();
    }

    public void add(String item, int num) {
        if (num <= 0) {
            throw new IllegalArgumentException();
        }
        BagItem bi = getItem(item);
        if (bi == null) {
            data.add(new BagItem(item, num));
        } else {
            bi.addNum(num);
        }
    }

    public boolean contains(String item) {
        BagItem bi = getItem(item);
        return (bi != null);
    }

    public Integer remove(String item) {
        BagItem bi = getItem(item);
        if (bi != null) {
            data.remove(bi);
            return bi.getNum();
        }
        return null;
    }

    public boolean remove(String item, int num) {
        if (num <= 0) {
            throw new IllegalArgumentException();
        }
        BagItem bi = getItem(item);      
        if (bi == null) {
            return false;
        }
        int left = bi.getNum() - num;
        if (left > 0) {
            bi.setNum(left);
        } else {
            remove(item);
        }
        return true;
    }

    public int howMany(String item) {
        BagItem bi = getItem(item);
        if (bi != null) {
            return bi.getNum();
        }
        return 0;
    }

    public boolean isEmpty() {
        return data.isEmpty();
    }

    public void clear() {
        data.clear();
    }
    
    public ArrayList<String> items() {
        ArrayList<String> items = new ArrayList<>();
        for (BagItem bi : data) {
            items.add(bi.getItem());
        }
        return items;
    }

    public Bag union(Bag bag) {
        Bag result = new Bag();
        for (BagItem bi : bag.data) {
            result.add(bi.getItem(), bi.getNum());
        }
        for (BagItem bi : data) {
            result.add(bi.getItem(), bi.getNum());
        }
        return result;
    }

    public Bag intersection(Bag bag) {
        Bag result = new Bag();
        for (BagItem otherBi : bag.data) {
            for (BagItem ownBi : data) {
                if (otherBi.getItem().equals(ownBi.getItem())) {
                    result.add(otherBi.getItem(), Math.min(otherBi.getNum(), ownBi.getNum()));
                }
            }
        }
        return result;
    }
    
    public Bag difference(Bag bag) {
        Bag result = new Bag();
        for (BagItem bi : data) {
            result.add(bi.getItem(), bi.getNum());
        }
        for (BagItem bi : bag.data) {
            result.remove(bi.getItem(), bi.getNum());
        }
        return result;
    }
    
    private BagItem getItem(String item) {
        for (BagItem bi : this.data) {
            if (item.equals(bi.getItem())) {
                return bi;
            }
        }
        return null;
    }

    @Override
    public String toString() {
        return "Bag{" + "data=" + data + '}';
    }
}
