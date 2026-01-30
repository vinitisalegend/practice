/**
 * Node.js Installation Diagnostic Script
 * --------------------------------------
 * This script uses ONLY Node.js core modules.
 * It cannot run in a browser.
 * If this executes successfully, your Node installation is healthy.
 */

"use strict";

const fs = require("fs");
const os = require("os");
const path = require("path");
const crypto = require("crypto");
const { pipeline } = require("stream/promises");

async function runDiagnostics() {
  console.log("=== Node.js Diagnostic Started ===\n");

  // 1. Runtime info
  console.log("Runtime Info:");
  console.log("Node Version:", process.version);
  console.log("Platform:", process.platform);
  console.log("Architecture:", process.arch);
  console.log("PID:", process.pid);
  console.log();

  // 2. OS info
  console.log("OS Info:");
  console.log("Hostname:", os.hostname());
  console.log("CPU Cores:", os.cpus().length);
  console.log("Total Memory (GB):", (os.totalmem() / 1e9).toFixed(2));
  console.log("Free Memory (GB):", (os.freemem() / 1e9).toFixed(2));
  console.log();

  // 3. File system test
  const testDir = path.join(__dirname, "node_test");
  const testFile = path.join(testDir, "test.txt");

  if (!fs.existsSync(testDir)) {
    fs.mkdirSync(testDir);
  }

  fs.writeFileSync(testFile, "Node.js filesystem test OK\n", "utf8");

  const fileContent = fs.readFileSync(testFile, "utf8").trim();
  console.log("File System Test:", fileContent);
  console.log();

  // 4. Stream test (Node-only)
  const streamOutput = path.join(testDir, "stream_output.txt");

  await pipeline(
    fs.createReadStream(testFile),
    crypto.createHash("sha256"),
    fs.createWriteStream(streamOutput)
  );

  console.log("Stream + Crypto Test: SHA-256 hash written to file");
  console.log();

  // 5. Environment variable access
  console.log("Environment Test:");
  console.log("USERPROFILE:", process.env.USERPROFILE || "Not set");
  console.log();

  // 6. Event loop / async test
  await new Promise((resolve) => setTimeout(resolve, 500));
  console.log("Async/Await Test: Event loop operational");
  console.log();

  // 7. Memory usage
  const mem = process.memoryUsage();
  console.log("Memory Usage (MB):");
  console.log("RSS:", (mem.rss / 1e6).toFixed(2));
  console.log("Heap Used:", (mem.heapUsed / 1e6).toFixed(2));
  console.log();

  console.log("=== Node.js Diagnostic Completed Successfully ===");
}

runDiagnostics().catch((err) => {
  console.error("❌ Diagnostic Failed");
  console.error(err);
  process.exit(1);
});
