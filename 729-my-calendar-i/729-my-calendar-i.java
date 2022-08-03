class MyCalendar {
    TreeMap<Integer,Integer> booking;
    public MyCalendar() {
        booking = new TreeMap<>();
    }
    
    public boolean book(int start, int end) {
        Integer prev=booking.floorKey(start),next=booking.ceilingKey(start);
        
        if((prev==null || booking.get(prev)<=start)&&(next==null || next>=end)){
            booking.put(start,end);
            return true;
        }
        return false;
            
    }
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * boolean param_1 = obj.book(start,end);
 */