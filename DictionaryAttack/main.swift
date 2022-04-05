import Crypto
import Foundation

//////////////////////////////////////////////////
// Dictionary Attack to get Kocher's Password
//////////////////////////////////////////////////

// Use a dictionary attack to solve the password of Mr. Kocher which is encrypted with either SHA256, SHA 512, MD5, or Blowfish
// Kocher's password hash: 3a8b7b53ab2be90f457869961f475aab

// Function to encrypt a message into data

func encrypt(input: [UInt8]) throws -> Data {
    // Don't forget to save your key somewhere!
    let key = SymmetricKey(size: .bits256)
    let sealedBox = try AES.GCM.seal(input, using: key)
    return sealedBox.combined!
}

func dictionaryAttack() -> String {

    let desiredHash = "3a8b7b53ab2be90f457869961f475aab"
    var passwordGuess = ""

    // Go through dictionary and assign the word to passwordGuess

    // passwordGuess = dictionaryWordThingyHere
    let guessAsData = encrypt(passwordGuess)
    
    // SHA-256
    let sha256Hash = SHA256.hash(data: guessAsData)

    
    // SHA-512
    let sha512Hash = SHA512.hash(data: guessAsData)


    // MD5
    let md5Hash = MD5.hash(data: guessAsData)


    // Blowfish
    let blowfishHash = Blowfish.hash(data: guessAsData)

    

    // Switch to see if any hashes of are equal to the desired hash
    switch desiredHash {
    case sha256Hash:
        break
    case sha512Hash:
        break
    case md5Hash:
        break
    case blowfishHash:
        break
    default:
        print("\(passwordGuess) is not the password")
    }
    
}
