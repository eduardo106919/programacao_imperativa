# MINI TESTE 2

## PERGUNTA 1

Qual é a **soma das frequências** dos caracteres 'f', 'l' e 't' na seguinte string (array de caracteres)?

*(What is the **sum of the frequencies** of the characters 'f', 'l' and 't' in the following string (array of chars)?)*

```C
char *sequencia = "NaBTLkfXatyWD3wN5MPqqFwT1QgPXKADAZvGqyORgAH3UQihu4EqaLAsDJlvSHSCROaHn
                   sN0W1n2sk1PBkQ0FNJytlWJoMB0fdZKas2IhCr1SpyPtcMXCH6oAcOASZUaBIrFhJ9NW9
                   TkPvKLDSVAo0W5gW9Vo5yF3b4bDrNDK9PWULf6980bSZJivtz6WzNrViWSkwYdJVuB9D9
                   6uadQD9uPs3tpT8yLEwLqgtYRzCQC36L96MHZ3brBJ6s8XDRC3qvZc00tGb2nl1Cr19N2
                   OvhrL0qDbE1kr92kBTv8ezFHCdxdkFUZPT1769yaXHWxrpKxqZdo4G0ovRYKVbhyf98y0
                   9oWVCyaE07nnFH7LDnypMtuS1dtpqjuhRq6xFJbpBURK5mtG1qQCOH9gKujBwGKlJaLjq
                   6WHVQyra3jCCRTwiCHIjF1RwTknINau47yS2ePjy0AUag7BiJTjgppoUJN7iAkEwNfxeC
                   UZoH73LTRexVdbjT8JqPF6CcUJTmFZm9phkPsMHkmQzxRoDWVwSVOXj9g5NdPg05Lxdyb
                   HhUL0GE9tlINLZAwmJnCELryci19h7kG3t9HemzUzvi300vgUYLcIihza8EpIptHD0g0I
                   bijtnkYdDuH1X4qdaGWSFWdNJrCUYtZNQWDhlWqBkIlZHPR5Y2wngUsn2S1kzzLThUTZg
                   GdnMYo4MA5LMs45pTmtsNd2SholegyboX9U0gVymkLzJUXwTSSVLrBssRNpK3yenQelwD
                   FXHQS52yeTf935b0CQQUEeACYxR3wgveJqWySKKugU9a8d9tLSqDf6HNQ6rhXeySe32hq
                   wUsEOqLmHLGkdcnDaRd61zHv7wOCOFdohaO5bI3WyRDkY42KdVm2zubGwMLuWCojx3lAj
                   CmS7vvXfS2sGZv8W1TH5wFCuQThz8RjiAWv7TnoUXWGsmXLtTKNjknjIId0VD3sKDsm7N
                   ZM7DHCxwac0bgygkVcdlMRFcpiGhkKwohBItehqGY5YXjdr3keLhf6giC1";
```

## PERGUNTA 2

Qual é a substring de **5 caracteres com menor valor lexicográfico** na seguinte sequência de caracteres (string)?

*(Which **5-character substring has the lowest lexicographic value** in the following string?)*

Por exemplo, na sequência `"OlaInformatica"`, ao utilizar 3 caracteres consecutivos, encontramos as seguintes substrings:

*(For example, in the string `"OlaInformatica"`, when using 3 consecutive characters, we find the following substrings:)*

```C
["Ola", "laI", "aIn", "Inf", "nfo", "for", "orm", "rma", "mat", "ati", "tic", "ica"]. 
```

Portanto, a resposta correta é `"Inf"`, por possuir menor valor lexicográfico.

*(Therefore, the correct answer is `"Inf"`, as it has less lexicographic value.)*

```C
char *sequencia = "NY7diLIIWXHRY2HNG0hJXmxRT5eUrnSLV6RNDdIaWI5XhGqhZrWem9Xr9M2RDDjGIsj800
                   X2s8muvjCPKWx4yUqK8QKq3DXyQQnW5bvp1GL7dTZ3sPYEcFFdr8kV5kJ2TAVaQzMDDAN1
                   f23egBN1hDqXLFQwcwddJf1tKhe5RwvteyEpKQF4F8TOkO28UIj6GqE1aGb739Lp4IoxB7
                   7EAeNc5oeB4k11oanSHWXUmqZOXTC8MGFhljHwTTWgyMco9ZAbdQSp5XRWibTEJC9Z4Rbb
                   4wEISvQToRNFXCXo1MYaiVa26xeZDULLkaVZNVCKS3lqNbEH9ZnN2IpW5cx0PX8oWB8n7d
                   opXna7w2TXaU1t7lsMe7QXoFdXvCWJ7XUC97ePJP8X3WUXnwYT3K7pWTlbINLKXgTKUIdm
                   42DvI1IqgVddOTKJwceeBw5WXqlzitizzYVq9Cqlk9nzVR7qfwvuROrYUEW5gCB6pkitPI
                   UGFYmECbv1l2vr8iyffiIjIK9o2TxDFOopJwbLtZsryDRgscnDv6bqvjgcGlkHXffel315
                   6kJHPZHPBoJL9EzboM0FBBelqn7Mrnr56sDNOgDAmryDR4l2UZ0xqOeZFLFovRMXo3NKV2
                   4GHvNKw1ZPaoAAQlF2rwNBxRTY3iY5LdcxsB0VSPMadtSTn6xOjlzlatR8Gy8cizwdqBJ9
                   w5SXaC5BolvTh1gY8F3DHt43iNzQgdoEUGssjul7a5HmQ4AwuMBOLwbsuNhKzYAJkNSHaR
                   PH3Kp0irzVVRDnyeKzYk9Uzt5RnZYtGhKvoK7OKnGRznzT0DibTQTLIAPduRnrkmtfAKtt
                   rmyLFpSPjR9B6dTAJP8vOqe1b2Ylcqjz3eiUeUh80t1SIrL8ZW92LksOqrY3Ge1qIYLcTz
                   VC2quzoh95xX2NmWiQSUBHOJfAeqSnPPbxHZfyW0GkfKGyAGtal05pD8xbSUbSFFOVCrnV
                   1bDqnlww1Nu889cwIRKj2g2KzJBR9I4ZD0ukUT8OylkC";
```
----------------------------------------------------------------------------------------------

## Respostas

PERGUNTA 1 == **39**

PERGUNTA 2 == **"00X2s"**

