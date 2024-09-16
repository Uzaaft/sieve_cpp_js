function sieveOfEratosthenes(n) {
  let primes = new Array(n + 1).fill(true);
  primes[0] = false;
  primes[1] = false;
  for (let i = 2; i <= Math.sqrt(n); i++) {
    if (primes[i]) {
      for (let j = i * i; j <= n; j += i) {
        primes[j] = false;
      }
    }
  }
  let result = [];
  for (let i = 2; i <= n; i++) {
    if (primes[i]) {
      result.push(i);
    }
  }
  return result;
}

function isPrimeNumber(n) {
  if (n <= 1) {
    return false;
  }
  for (let i = 2; i * i <= n; i++) {
    if (n % i === 0) {
      return false;
    }
  }
  return true;
}

function main() {
  if (process.argv.length < 3) {
    console.error("Usage: node sieve_benchmark.js <n>");
    process.exit(1);
  }

  const n = parseInt(process.argv[2], 10);

  if (isNaN(n) || n <= 0) {
    console.error("Please provide a valid positive integer.");
    process.exit(1);
  }

  const start = process.hrtime();

  sieveOfEratosthenes(n);

  const end = process.hrtime(start);
  const duration = end[0] + end[1] / 1e9;

  console.log(
    `Time taken to find primes up to ${n}: ${duration.toFixed(6)} seconds`,
  );
}

main();
