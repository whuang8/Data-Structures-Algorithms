import org.junit.*;

public class SortTests{
    private static SortingFunctions functions;
    
    @BeforeClass
    public static void setUp(){
        functions = new SortingFunctions();
    }

    @Test
    public void testInsertionSort(){
        int[] input = { 15,5,14,7,13,6,12,8,2,11,4,1,10,9,3 };
        int[] expected = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
        functions.insertionSort(input);
        Assert.assertArrayEquals(input, expected);
    }
}


