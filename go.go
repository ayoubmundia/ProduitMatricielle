package main

import "fmt"
import "time"

func main() {

  var matrixA [550][550]int
  var matrixB [550][550]int
  var result [550][550]int
  var i, j, k, m, n, p, q, total int

  m = 550
  n = m
  p = n
  q = p
  total = 0


  start := time.Now()
  if n != p {
    fmt.Println("Error: The matrix cannot be multiplied")
  } else {

    for i = 0; i < m; i++ {
      for j = 0; j < n; j++ {
		matrixA[i][j] = 10000
      }
    }

    for i = 0; i < p; i++ {
      for j = 0; j < q; j++ {
		matrixB[i][j] = 15000
      }
    }

    for i = 0; i < m; i++ {
      for j = 0; j < q; j++ {
        for k = 0; k < p; k++ {
          total = total + matrixA[i][k]*matrixB[k][j]
        }
        result[i][j] = total
        total = 0
      }
    }

  }

  t := time.Now()

  elapsed := t.Sub(start)

  fmt.Printf("Execution Time : => %.6f \n", elapsed.Seconds())

}