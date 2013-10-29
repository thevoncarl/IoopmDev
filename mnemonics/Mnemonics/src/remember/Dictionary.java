package remember;

import java.io.*;
import java.util.*;

public class Dictionary {
    private final Set<String> words ;
    
    
     public Dictionary (){
    words = new HashSet<String>();
}
      private Dictionary(HashSet<String> _) {
      words = _;
    }
    
    public static Dictionary createFromFile(final String fileName) {
	return createFromFile(new File(fileName));
    }

    public static Dictionary createFromFile(final File f) {
	final Dictionary dict = new Dictionary();
	FileUtils.processEachLine(f, new FileUtils.Apply() {
                @Override
		public void apply(String word) {
		    dict.insert(word.trim());
		}
	    });
	return dict;
    }


    public void insert(String word) {
	words.add(word);
    }

    public boolean contains(String word) {
	return words.contains(word);
    }
    public Dictionary couldMatch(String match) {
         final HashSet<String> _ = new HashSet<String>();
            for (String word : words) {
        if (word.startsWith(match)) _.add(word);
}
    return (_.size() > 0) ? new Dictionary(_) : null;
}
    

    @Override
    public String toString() {
	return "Dictionary(" + words + ")";
    }
}
