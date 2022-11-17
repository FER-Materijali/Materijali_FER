/*
 * LR1Tokenizer.java
 *
 * THIS FILE HAS BEEN GENERATED AUTOMATICALLY. DO NOT EDIT!
 */

import java.io.Reader;

import net.percederberg.grammatica.parser.ParserCreationException;
import net.percederberg.grammatica.parser.TokenPattern;
import net.percederberg.grammatica.parser.Tokenizer;

/**
 * A character stream tokenizer.
 *
 *
 */
class LR1Tokenizer extends Tokenizer {

    /**
     * Creates a new tokenizer for the specified input stream.
     *
     * @param input          the input stream to read
     *
     * @throws ParserCreationException if the tokenizer couldn't be
     *             initialized correctly
     */
    public LR1Tokenizer(Reader input) throws ParserCreationException {
        super(input, false);
        createPatterns();
    }

    /**
     * Initializes the tokenizer by creating all the token patterns.
     *
     * @throws ParserCreationException if the tokenizer couldn't be
     *             initialized correctly
     */
    private void createPatterns() throws ParserCreationException {
        TokenPattern  pattern;

        pattern = new TokenPattern(LR1Constants.A,
                                   "a",
                                   TokenPattern.STRING_TYPE,
                                   "a");
        addPattern(pattern);

        pattern = new TokenPattern(LR1Constants.B,
                                   "b",
                                   TokenPattern.STRING_TYPE,
                                   "b");
        addPattern(pattern);

        pattern = new TokenPattern(LR1Constants.C,
                                   "c",
                                   TokenPattern.STRING_TYPE,
                                   "e");
        addPattern(pattern);
    }
}
