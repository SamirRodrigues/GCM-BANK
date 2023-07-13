const express = require("express");
const cors = require("cors");
const app = express();
const router = require("./router/routes");

/**
 * Middlewares 
 */
app.use(express.json());
app.use(cors());
app.use(router);

/**
 * Start server
 */
app.listen(8080, () => console.log("Server is Running! 🤌"));
