package util.ga;

import java.util.Random;

public interface IndividualProvider {
    
    public abstract Solution next(Random random);

}