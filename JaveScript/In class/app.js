//npm install readline-sync
const rls = require('readline-sync')

let amount, time, rate;

// Ask the user for amount borrwoed (keep asking until i get it right)
while (!amount || amount <= 0) // do this if amount is not defined, or if amount is less than 0.
{
    amount = parseFloat(rls.question("Please enter the amount borrwoed in dollars: "));
}

// ask the user for the time preiod (in years)
while (!time || time <= 0) // do this if amount is not defined, or if amount is less than 0.
{
    time = parseInt(rls.question("Please enter the number of years the loan is for: "));
}

// ask theuser for interest rate
while (!rate || rate <= 0) // do this if amount is not defined, or if amount is less than 0.
{
    rate = parseFloat(rls.question("Please enter the interest rate in percent: "));
}

console.log("The principal plus interest is: $" + calcInterest(amount, time, rate));

// calculate the interest rate and return the value of interest + principle
function calcInterest(amount, time, rate) {
    const pct = rate / 100;
    return pct;
}