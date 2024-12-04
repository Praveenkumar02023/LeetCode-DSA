class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;

        List<Integer> res = new ArrayList<>();

        int rowStart = 0 , colStart = 0 , rowEnd = n-1 , colEnd = m-1;

        while(rowStart <= rowEnd && colStart <= colEnd){

            for(int ptr = colStart ; ptr <= colEnd ; ptr++){
                res.add(matrix[rowStart][ptr]);
            }
            rowStart++;

            for(int ptr = rowStart ; ptr <= rowEnd ; ptr++){
                res.add(matrix[ptr][colEnd]);
            }
            colEnd--;

           if(rowStart <= rowEnd){

            for(int ptr = colEnd ; ptr >= colStart ; ptr--){
                res.add(matrix[rowEnd][ptr]);
            }
            rowEnd--;
           } 
            
            if(colStart <= colEnd){
            for(int ptr = rowEnd ; ptr >= rowStart ; ptr--){
                res.add(matrix[ptr][colStart]);
            }
            colStart++;

            }
        }
        for(int x : res) System.out.print(x);
        return res;
    }
}