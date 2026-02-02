import java.time.LocalDateTime
import java.time.format.DateTimeFormatter

data class User(
    val name: String,
    val age: Int
)

fun main() {
    println("=== Kotlin CLI Demo Application ===")

    val user = readUser()
    greetUser(user)

    val now = currentTimestamp()
    println("Run completed at: $now")
}

fun readUser(): User {
    print("Enter your name: ")
    val name = readLine()?.trim().orEmpty()

    print("Enter your age: ")
    val ageInput = readLine()
    val age = ageInput?.toIntOrNull() ?: 0

    return User(name = name, age = age)
}

fun greetUser(user: User) {
    println()
    println("Hello, ${user.name}")
    println("Age recorded: ${user.age}")

    if (user.age >= 18) {
        println("Status: Adult")
    } else {
        println("Status: Minor")
    }
}

fun currentTimestamp(): String {
    val formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss")
    return LocalDateTime.now().format(formatter)
}
